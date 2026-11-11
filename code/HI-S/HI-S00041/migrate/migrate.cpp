#include<bits/stdc++.h>
using namespace std;
int c,T;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	for(int t=0;t<T;t++){
		int n,d,ans=0;
		scanf("%d%d",&n,&d);
		vector<vector<int> > g(n+1);
		vector<int> x(n);
		
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		sort(x.begin()+1,x.end()+1);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n and x[j]-x[i]<=d;j++){
					g[i].push_back(j);
					g[j].push_back(i);
			}
		}
		vector<vector<bool> > had(n+1,vector<bool>(n+1,0));
		for(int i=1;i<=n;i++){
			priority_queue<int> dij;
			vector<int> dist(n+1,0x3f3f3f3f);
			vector<bool> vis(n+1,0) ;
			dij.push(i);
			dist[i]=0;
			vis[i]=1;
			while(!dij.empty()){
				int u=dij.top();
				vis[u]=1;
				dij.pop();
				for(int j=0;j<g[u].size();j++){
					int v=g[u][j];
					if(dist[v]>dist[u]+1){
						ans-=had[i][v]==1?1:0;
						had[i][v]=had[v][i]=0;
						dist[v]=dist[u]+1;
					}
					else if(dist[v]==dist[u]+1 and !had[i][v]){
						ans++;
						had[i][v]=1;
						had[v][i]=1;
					}
					if(vis[v])continue;
					dij.push(v);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
