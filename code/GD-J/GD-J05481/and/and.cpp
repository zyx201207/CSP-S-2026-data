#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n = 0, m = 0;
	cin >> n >> m;
	auto cj = [&](int n){
		string s;
		int pos = -1;
		while(n > 0){
			if(n % 2 == 0)
				s += '0';
			else s += '1';
			n /= 2;
		}
		reverse(s.begin(), s.end());
		int cnt = 0;
		pos = s.size();
		return pos;	
	};
	vector<pair<int, int>> c(n); 
	for(int i = 0;i < n;i++){
		cin >> c[i].second;
		c[i].first = cj(c[i].second);
	}
	sort(c.begin(), c.end());
	reverse(c.begin(), c.end());
	long long ans = 0;
	auto dfs = [&] (auto && self, int i, int cnt, long long res){
		if(cnt == m){
			ans = max(ans, res);
			return;
		}
		for(int j = i + 1;j < n;j++){
			self(self, j, cnt + 1, res & c[j].second);
		}
	};
	for(int i = 0;i < n;i++){
		long long s = c[i].second;
		dfs(dfs, i, 1, s);
	}
	cout << ans << endl;
	return 0;
}
