#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, ans;
vector<int> v, nxt;
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1, x; i <= n; i++){
		cin >> x;
		v.emplace_back(x);
	}
	for(int i = 30; i >= 0; i--){
		int cnt = 0;
		for(int j = 0; j < (int)v.size(); j++){
			int val = v[j];
			cnt += (val >> i & 1);
		}
		if(cnt >= m){
			nxt.clear();
			for(int j = 0; j < (int)v.size(); j++){
				int val = v[j];
				if((val >> i & 1)) nxt.emplace_back(val);
			}
			v.swap(nxt);
			ans |= (1 << i);
		}
	}
	cout << ans;
	return 0;
}
/*
首先考虑拆位，发现从高到低考虑不劣

每次将当前二进制位中为1的先塞入vector，如果发现1的个数无法满足m，就将这一位放空，然后保留所有，否则只保留为1的，因为优先高位考虑更优 

这个居然让我想了一会 

4 2
3 15 12 12

5 3
31 3 1 15 7
*/
