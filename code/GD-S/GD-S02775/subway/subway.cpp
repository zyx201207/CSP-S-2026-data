#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int N=505;
int n,m,c,d,q,w[N];
vector<pii> e[N];

int dij(int s,int t){
	int dis[N];
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push({0,s});
	dis[s]=0;
	while (!q.empty()){
		pii h=q.top();q.pop();
		int d=h.first,u=h.second;
		if(d>dis[u])continue;
		for(auto g:e[u]){
			int v=g.first,w=g.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	return dis[t];	
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int T=i+m;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			e[T].push_back({a,t});
			e[a].push_back({T,t});
		}
	}
	
	while(q--){
		int u,v;cin>>u>>v;
		int ans=dij(u,v);
		ans=ans+w[u]+w[v];
		cout<<ans<<endl; 
	}
	return 0;
} 
