#include <bits/stdc++.h>
#define int long long
using namespace std;

struct n{
	int cnt, q;
	char ch;
};

signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	#if 1
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	#endif
	
	int a;
	cin >> a;
	
	vector<n> sz(1, {1, -1, 0});
	
	while(a --){
		int cnt;
		char ch;
		
		cin >> cnt >> ch;
		
		if(sz.back().ch == ch)
			sz.back().cnt += cnt;
		else
			sz.push_back({cnt, 0, ch});
	}
	
//	cerr << sz.size() << endl;
	
	sz.push_back({0, 0, 0});
	
	for(int i = 1; i != sz.size(); ++ i)
		sz[i].q = sz[i - 1].q + sz[i - 1].cnt;
	
	auto upper_bound = [&](int i) -> int{
		int l = 1, r = sz.size() - 1, ans = 1;
		
		while(l <= r){
			int mid = l + r >> 1;
			
			if(sz[mid].q > i)
				ans = mid,
				r = mid - 1;
			else
				l = mid + 1;
		}
		
		return ans;
	};
	
	vector<vector<int>> qe(26, vector<int> (sz.size(), 0));
	
	for(int i = 0; i != 26; ++ i)
		for(int j = 1; j != sz.size(); ++ j)
			qe[i][j] = (sz[j].cnt * (sz[j].ch != (i + 'a'))) + qe[i][j - 1];
	
	auto query = [&](int i, char ch) -> int{
		if(i < 0)
			return 0;
		
		int u = upper_bound(i) - 1;
		
		return qe[ch - 'a'][u - 1] + (i - sz[u].q + 1) * (sz[u].ch != ch);
	};
	
	int ans = 0;
	
	for(int i = 1; i < sz.size() - 1; ++ i){
		int rvl = sz.back().q - sz[i + 1].q;
		int rvr = sz.back().q - sz[i].q - 1;
		
		if(rvl > rvr)
			swap(rvl, rvr);
		
		ans += query(rvr, sz[i].ch);
		ans -= query(rvl - 1, sz[i].ch);
		
//		cerr << i << ": " << rvr << " " << query(rvr, sz[i].ch) << ", " << rvl << " " << query(rvl - 1, sz[i].ch) << endl;
	}
	
	cout << (ans >> 1);
	
	return 0;
}
