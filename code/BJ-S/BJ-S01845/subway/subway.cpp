#include<bits/stdc++.h>
#define PII pair<int,int>
#define int long long
using namespace std;
const int N = 5e5 + 5,M = 505,INF = 1e18;
int d[M][M],c,n,m,dd,q,w[N];
vector<PII> s[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> dd >> q ;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) d[i][j] = INF; 
		d[i][i] = 0;
	}
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++) {
		int ki,x,c;
		cin >> ki;
		for(int j=1;j<=ki;j++) {
			cin >>x >> c;
			s[x].push_back(make_pair(i,c));
		}
	}
	for(int i=1;i<=m;i++) {
		int k = s[i].size();
		for(int u=0;u<k;u++) {
			for(int v=u+1;v<k;v++){
				int x = s[i][u].first,y = s[i][v].first;
				int cst = s[i][u].second + s[i][v].second;
				d[x][y] = min(d[x][y],cst);
				d[y][x] = d[x][y];
			}
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			if(d[i][k] == INF) continue;
			for(int j=1;j<=n;j++) {
				if(d[k][j] == INF) continue;
				d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++) {
		int p,q,res = INF;
		cin >> p >> q ;
		for(int j=0;j<(int)s[p].size();j++){
			for(int k=0;k<(int)s[q].size();k++) {
				res = min(res,w[p]+w[q]+d[s[p][j].first][s[q][k].first]+s[p][j].second+s[q][k].second);
			}
		}
		cout << res << "\n";
	}
	return 0;
}