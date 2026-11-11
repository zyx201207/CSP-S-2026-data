#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int INF=0x3f3f3f3f;
struct node{
	int v,w;
};
int c,n,m,d,q,w[N],a[N],t[N],dis[N];
vector<node>rd[N];
//bool vis[N];
void dij(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	pq.push({0,s});
	for(int i=1;i<=m;i++){
		dis[i]=INF;
	}dis[s]=0;
	while(!pq.empty()){
		auto top=pq.top();
		pq.pop();
		int u=top.second;
		for(int i=0;i<rd[u].size();i++){
			int v=rd[u][i].v,w=rd[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
		//cin>>w[i];
	}for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}for(int j=1;j<k;j++){
			for(int b=j+1;b<=k;b++){
				rd[a[j]].push_back({a[b],t[j]+t[b]});
				rd[a[b]].push_back({a[j],t[j]+t[b]});
			}
		}
	}for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		dij(u);
		printf("%lld\n",w[u]+w[v]+dis[v]);
		//cout<<w[u]+w[v]+dis[v]<<endl;
	}
	return 0;
}

