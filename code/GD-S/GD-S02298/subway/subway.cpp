#include<bits/stdc++.h>
using namespace std;
long long w[500010],tt[510][50010],aa[510][50010];
vector<int> p[500010];
long long g[510][510];
const long long INF=1e18;
bool vis[510];
int c,m,n,d,q;
void dfs(int s,int x,int depth){
	vis[x]=true;
	g[s][x]=min(1LL*depth,g[s][x]);
	g[x][s]=min(1LL*depth,g[x][s]);
	for(int i = 0;i < n;i++){
		if(g[x][i]>=0&&g[x][i]!=INF){
			if(!vis[i])dfs(s,i,depth+g[x][i]);
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0;i < m;i++){
		cin >> w[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			g[i][j]=INF;
		}
	}
	for(int i = 0;i < n;i++){
		int t;
		cin >> t;
		for(int j = 0;j < t;j++){
			cin >> aa[i][j];
			aa[i][j]--;
			cin >> tt[i][aa[i][j]];
			p[aa[i][j]].push_back(i);
		}
	}
	
	for(int i = 0;i < m;i++){
		if(p[i].size()>1){
			for(int u = 0;u < p[i].size();u++){
				for(int v = 0;v < p[i].size();v++){
					if(u!=v){
						g[u][v]=min(g[u][v],tt[u][i]+tt[v][i]);
						//cout << tt[u][i] << " " << tt[v][i] << endl;
					}
				}
			}
		}
	}
//	cin >> n;
//	for(int i = 0;i < n;i++){
//		for(int j = 0;j < n;j++){
//			cin >> g[i][j];
//		}
//	}
	for(int i = 0;i < n;i++){
		g[i][i]=0;
	}
	for(int i = 0;i < n;i++){
		memset(vis,false,sizeof(vis));
		vis[i]=true;
		dfs(i,i,0);
	}
//	for(int i = 0;i < n;i++){
//		for(int j = 0;j < n;j++){
//			cout << g[i][j] << " ";
//		}cout << endl;
//	}
	for(int i = 0;i < q;i++){
		int x,y,au,av;
		cin >> x >> y;
		x--;y--;
		int tu=p[x][0],tv=p[y][0];
		long long ans=g[tu][tv];
		au=tu;
		av=tv;
		//cout << 33;
		for(int u:p[x]){
			for(int v:p[y]){
//				cout << u << " " << v<< endl;
				if(g[u][v]<=ans){
					ans=g[u][v];
					au=u;
					av=v;
				}
			}
		}
		//cout << au << " " << av  << " " << ans << endl;
		cout << w[x]+w[y]+ans+tt[au][x]+tt[av][y] << endl;
	}
} 
