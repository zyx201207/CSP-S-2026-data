#include <bits/stdc++.h>
using namespace std;

long long t, ans, w[500002], floyd[502][502];
int a, b, c, n, m, d, p, q;
vector<pair<int, long long>> s[500002];
int main(){
		
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;	
	
	for(int i = 1; i <= m; ++i){
		cin>>w[i];
	} 
	
	for(int i = 1; i <= n; ++i){
		cin>>p;
		while(p--){
			cin>>a>>t;
			s[a].push_back({i, t});
		}
	}
	
	memset(floyd, 0x3f, sizeof(floyd));
	for(int i = 1; i <= n; ++i){
		floyd[i][i] = 0;
	}
	
	for(int k = 1; k <= m; ++k){
		if(s[k].size() > 1){
			for(int i = 0; i < s[k].size(); ++i){
				for(int j = i+1; j < s[k].size(); ++j){
					floyd[ s[k][i].first ][ s[k][j].first ] = min(floyd[ s[k][i].first ][ s[k][j].first ], s[k][i].second + s[k][j].second);
				}
			}
		}
	}
	
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = i+1; j <= n; ++j){
				if(k <= i){
					floyd[i][j] = min(floyd[i][j], floyd[k][i] + floyd[k][j]);
				}else if(k >= j){
					floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[j][k]);
				}else{
					floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
				}
			}
		}
	}
	
	while(q--){
		cin>>a>>b;
		ans = 1e18;
		for(auto i : s[a]){
			for(auto j : s[b]){
				if(i.first < j.first){
					ans = min(ans, i.second + floyd[i.first][j.first] + j.second);
				}else{
					ans = min(ans, i.second + floyd[j.first][i.first] + j.second);
				}
			}
		}
		cout<<ans+w[a]+w[b]<<'\n';
	}
	return 0;
}
