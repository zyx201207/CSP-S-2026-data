#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	vector<int> nums(n);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	vector<int> nums1(m);
	int nums2[200000];
	for (int i = 0; i < m; i++) {
		nums1[i] = nums[i];
	}
	int a = nums1[0];
	while (m--) {
		for (int i = 0; i < n ;i++) {
			nums1[m] = nums[i];
			for (int j = 1; j < m; j++) {
				a = a & nums1[j];
			}
			nums2[i] = a;
		}
	}
	int b = nums2[0];
	for (int i = 0; i < 200000; i++) {
		if(nums2[i] > b) {
			b = nums2[i];
		}
	}
	cout << b;
	
	return 0;
}
