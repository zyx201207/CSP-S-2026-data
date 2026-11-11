#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=50e5+5;
int c;
int m,n,d,q,ww[inf];
int dis[inf+505],vis[inf+505];
int h[inf+505],to[inf+505],net[inf+505],w[inf+505],p;
void add(int u,int v,int wg){
	to[++p]=v;
	w[p]=wg;
	net[u]=h[u];
	h[u]=p;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(h,-1,sizeof(h));
	for(int i=1;i<=m;i++){
		cin>>ww[i];//¿Ú->Ìü 
	}
	for(int i=1;i<=n;i++){
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			add(a,m+i,t);
			add(m+i,a,t);
		}
	}
	while(q--){
		int x,y;
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >que;
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		cin>>x>>y;
		dis[x]=0;
		que.push({0,x});
		while(!que.empty()){
			int u=que.top().second;
			que.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(int i=h[u];~i;i=net[i]){
				int v=to[i],wg=w[i];
				if(dis[v]>dis[u]+wg){
					dis[v]=dis[u]+wg;
					que.push({dis[v],v});
				}
			}
		}
		cout<<ww[x]+ww[y]+dis[y]<<'\n';
	}
	return 0;
}

