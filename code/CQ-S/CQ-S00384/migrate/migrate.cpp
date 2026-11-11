#include <bits/stdc++.h>
using namespace std;
namespace contest{
	int c,T; 
	int x[2000005];
	int vis[2000005];
	int d[2000005];
	int edges[2000005];
	vector<int> edge[2000005];
	int dijkstra(int s,int t,int notd){
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
		memset(vis,0,sizeof(vis));
		memset(d,0x3f3f3f3f,sizeof(d));
		d[s]=0;
		vis[s]=1;
		q.push({d[s],s});
		while (!q.empty()){
			auto [ww,u]=q.top();
			q.pop();
			for (int v:edge[u]){
				if (vis[v]||v==notd) continue;
				if (d[v]>d[u]+1){
					d[v]=d[u]+1;
					vis[v]=1;
					q.push({d[v],v});
				}
			}
		}
		return d[t];
	}
	int main(){
		cin>>c>>T;
		while (T--){
			int n,d;
			cin>>n>>d;
			for (int i=1;i<=n;i++) cin>>x[i];
			for (int i=1;i<=n;i++){
				for (int j=i+1;j<=n;j++){
					if (abs(x[i]-x[j])<=d){
						edge[i].push_back(j);
					}
				}
			}
			int ans=0;
			for (int s=1;s<=n;s++){
				for (int t=s+1;t<=n;t++){
					int dist=dijkstra(s,t,-1);
					int cnt=0;
					for (int nt=1;nt<=n;nt++){
						if (nt==s||nt==t) continue;
						 if (dijkstra(s,t,nt)==dist) cnt++;
					}
					if (cnt==2){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	contest::main();
	return 0;
}
