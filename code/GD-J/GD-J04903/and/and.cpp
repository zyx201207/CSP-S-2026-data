#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin >> n >> m;
	vector<unsigned int> a(n);
	unsigned int ans = 0;
	for(auto &i : a) cin >> i;
	for(int i = 31; i >= 0; i--){
		int cnt = 0;
		for(auto &j : a){
			if((j & ans) != ans)continue;
			cnt += (j >> i) & 1u; 
		}
		if (cnt >= m) ans |= (1u << i);
	}
	cout << ans;
} 

