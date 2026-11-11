#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 505,MAXM = 5*1e5+5; 
int c,n,m,d,q,w[MAXM],k,in1,in2,x,y;
vector< pair<int,int> > mp[MAXM];
int floyd[MAXN][MAXN];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i<=m;i++){
		cin >> w[i];
	}
	for (int i = 1;i<=n;i++){
		cin >> k;
		for (int j = 1;j<=k;j++){
			cin >> in1 >> in2;
			mp[in1].push_back({i,in2}); 
		}
	}
	for (int i = 1;i<=n;i++){
		for (int j = 1;j<=n;j++){
			floyd[i][j] = 1e18;
		}
	}
	for (int i = 1;i<=n;i++){
		floyd[i][i] = 0;
	}
	for (int i = 1;i <= m;i++){
		for (int j = 0;j<mp[i].size();j++){
			for (int k = 0;k<mp[i].size();k++){
				int res1f = mp[i][j].first;
				int res1s = mp[i][j].second;
				int res2f = mp[i][k].first;
				int res2s = mp[i][k].second;
				if (res1f == res2f){
					continue;
				}
				floyd[res1f][res2f] = min(floyd[res1f][res2f],res1s + res2s);
			}
		}
	}
	for (int k = 1;k<=n;k++){
		for (int i = 1;i<=n;i++){
			for (int j = 1;j<=n;j++){
				floyd[i][j] = min(floyd[i][j],floyd[i][k] + floyd[k][j]);
			}
		}
	}
	for (int i = 1;i<=q;i++){
		cin >> x >> y;
		int ans = 1e18;
		for (int j = 0;j<mp[x].size();j++){
			for (int k = 0;k<mp[y].size();k++){
				int res1f = mp[x][j].first;
				int res1s = mp[x][j].second;
				int res2f = mp[y][k].first;
				int res2s = mp[y][k].second;
				ans = min(ans,res1s + res2s + floyd[res1f][res2f]);
			}
		}
		ans += w[x] + w[y];
		cout << ans << "\n";
	}
	return 0;
}
