#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int n,m,tot,T;
long long dis[MAXN],w[MAXN];
vector<pair<int,long long> > g[MAXN];
priority_queue<pair<long long,int> > q;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d; cin>>c>>n>>m>>d>>T; tot=m;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k,a;i<=n;i++){
		cin>>k; tot++;
		for(int j=1;j<=k;j++){
			long long t;
			cin>>a>>t;
			g[a].push_back({tot,t});
			g[tot].push_back({a,t});
		}
	}
	while(T--){
		memset(dis,0x3f,sizeof(dis));
		int s,e; cin>>s>>e;
		dis[s]=0; q.push({0,s});
		while(!q.empty()){
			int u=q.top().second; q.pop();
			for(auto i:g[u]){
				int v=i.first,w=i.second;
				if(dis[u]+w<dis[v]){
					dis[v]=dis[u]+w;
					q.push({dis[v],v});
				}
			}
		} cout<<w[s]+dis[e]+w[e]<<'\n';
	}
	return 0;
}
