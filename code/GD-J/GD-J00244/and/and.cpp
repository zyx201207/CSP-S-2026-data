#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	#if 1
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	#endif
	
	int a, b;
	cin >> a >> b;
	
	int ans = 0;
	
	vector<int> seq(a);
	
	for(auto &i : seq)
		cin >> i;
	
	for(int i = 29; i >= 0; -- i){
		vector<int> ns;
		
		for(const auto &j : seq)
			if((j >> i) & 1)
				ns.push_back(j);
		
		if(ns.size() >= b)
			seq.swap(ns),
			ans |= 1LL << i;
	}
	
	cout << ans;
	
	return 0;
}
