#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
const long long INF=0x3f3f3f3f;
int c,n,m,d,t;
int g[260][260][60];
int val[maxn],extra[510][2510],ans[260][260];
vector<int>vec[60];
vector<int>adj[maxn]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> t;
	for(int i=1;i<=m;i++) {
		cin >> val[i];
	}
	memset(g,INF,sizeof(g));
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int u;
			cin >> u;
			adj[u].push_back(i);
			cin >> extra[i][u];
			vec[i].push_back(u);
		}
		for(int j=0;j<k-1;j++){
			int u=vec[i][j],v=vec[i][j+1];
			g[u][v][i]=extra[i][u];
			g[v][u][i]=extra[i][u];
		}
	}
	memset(ans,INF,sizeof(ans));
	
	while(t--){
		int x,y;
		cin >> x >> y;
		cout << ans[x][y] << '\n';
	}
	return 0;
} 
