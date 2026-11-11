#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using numtype = int;

vector<bool> able;
vector<bool> tool;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	numtype n, m;
	cin >> n >> m;
	
	vector<vector<numtype>> nums(30, vector<numtype>());
	able.resize(n, true);
	tool.resize(n);
	
	for (numtype i = 0; i < n; ++i){
		numtype num;
		cin >> num;
		
		for (numtype k = 0; k < 30; ++k){
			if ((num >> k) & 1) nums[k].emplace_back(i);
		}
	}
	
	numtype ans = 0;
	
	for (numtype k = 29; k >= 0; --k){
		if (nums[k].size() < m) continue;
		
		fill(tool.begin(), tool.end(), false);
		numtype cnt = 0;
		
		for (numtype i : nums[k]){
			if (able[i]){
				tool[i] = true;
				++cnt;
			}
		}
		
		if (cnt < m) continue;
		
		able = tool;
		ans |= 1 << k;
	}
	
	cout << ans;
	
	return 0;
}
