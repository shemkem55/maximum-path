#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to calculate the maximum path sum
int maxPathSumUtil(TreeNode* node, int& maxSum) {
    if (node == nullptr) return 0; // Base case

    // Recursively calculate the maximum path sum for left and right subtrees
    int leftMax = max(maxPathSumUtil(node->left, maxSum), 0); // Ignore negative sums
    int rightMax = max(maxPathSumUtil(node->right, maxSum), 0); // Ignore negative sums

    // Update the maximum path sum considering the current node as the highest point
    maxSum = max(maxSum, node->val + leftMax + rightMax);

    // Return the maximum path sum extending from this node
    return node->val + max(leftMax, rightMax);
}

// Main function to return the maximum path sum of any non-empty path
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN; // Initialize to minimum integer value
    maxPathSumUtil(root, maxSum);
    return maxSum;
}

// Example usage
int main() {
    // Create a sample binary tree:
    //       -10
    //       /  \
    //      9   20
    //          /  \
    //         15   7
    
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Maximum path sum is: " << maxPathSum(root) << endl; // Output: 42

    // Clean up memory (not shown for brevity)

    return 0;
}