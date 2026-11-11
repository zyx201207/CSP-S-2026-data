#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
int c,n,m,dd,q;
int w[500005];
struct PIT{
	int k,w;
};
struct Edge{
	int to,w,xl;
};
vector<PIT> pit[500005]; 
vector<Edge> e[500005];
int d[500005],vis[500005],ex[500005];
priority_queue<pair<int,pair<int,int> > > p;
inline void dij(int s){
	for(int i=0;i<=m;i++){
		d[i]=inf;
		vis[i]=0;
		ex[i]=0;
	}d[s]=pit[s][0].w;
	p.push({d[s],{s,pit[s][0].k}});
	while(p.size()){
		int u=p.top().second.first;
		int dqxl=p.top().second.second;
		p.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int j=0;;j++){
			if(pit[u][j].k==dqxl){
				ex[u]=pit[u][j].w;
				break;
			}
		}
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].to,w=e[u][i].w,xl=e[u][i].xl;
			if(dqxl==xl){
				if(d[v]>d[u]+w){
					d[v]=d[u]+w;
					p.push({-d[v],{v,xl}});
				}
			}else{
				for(int j=0;;j++){
					if(pit[u][j].k==xl){
						if(u==s){
							int yy=0;
							for(int jj=0;;jj++){
								if(pit[u][jj].k==dqxl){
									yy=pit[u][jj].w;
									break;
								}
							}
							if(d[v]>d[u]+w+pit[u][j].w-yy){
								d[v]=d[u]+w+pit[u][j].w-yy;
								p.push({-d[v],{v,xl}});
							}
						}else{
							if(d[v]>d[u]+w+pit[u][j].w){
								d[v]=d[u]+w+pit[u][j].w;
								p.push({-d[v],{v,xl}});
							}
						}break;
					}
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> dd >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}for(int i=1,kk;i<=n;i++){
		cin >> kk;
		vector<int> aa;
		vector<int> tt;
		for(int j=1,a,t,la,lt;j<=kk;j++){
			cin >> a >> t;
			aa.push_back(a);
			tt.push_back(t);
			pit[a].push_back({i,t});
		}for(int j=0;j<kk;j++){
			for(int o=0;o<kk;o++){
				if(j!=o){
					e[aa[j]].push_back({aa[o],tt[o],i});
				}
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin >> x >> y;
		dij(x);
		cout << d[y]+w[x]+w[y] << '\n';
	}
	
	return 0;
}

