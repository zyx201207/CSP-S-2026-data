// /and/and.cpp

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <climits>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m, maxn = INT_MIN, maxnInd = -1;
	cin >> n >> m;
	vector<int> nums;
	for (int i = 0;i < n;i ++){
		int a;
		cin >> a;
		if (maxn < a) {
			maxn = a;
			maxnInd = i;
		}
		nums.push_back(a);
	}
	
	vector<bool> mark(n+2, false);
	// t[i-1]: 选择i数字可以达到的最大位与和
	vector<int> t(m+2, INT_MIN); 
	t[0] = maxn;
	mark[maxnInd] = true;
	/*                                        // TEST_COMMENT
	cout << "maxn: " << maxn << "\nmark: ";
	for (auto i:mark)cout << i << " ";
	cout << "\n" << "nums: ";
	for (auto i:nums)cout << i << " ";
	cout << "\n";
	*/
	
	for (int i = 1;i < m;i ++){
		// cout << i << ": \n";              // TEST_COMMENT
		int MAX = INT_MIN;
		for (int j = 0;j < n;j ++){
			int tmp = t[i-1] & nums[j]; 
			//                                  TEST_COMMENT
			// cout << "    " << j << ": " << t[i-1] << "  " << nums[j] << " -> " << tmp << "\n";
			if (tmp > MAX && !mark[j]){
				// cout << "      <use>\n";   // TEST_COMMENT
				MAX = tmp;
				mark[j] = true;
			}
		}
		
		t[i] = MAX;
	}
	
	cout << t[m-1];
	
	return 0;
} 
