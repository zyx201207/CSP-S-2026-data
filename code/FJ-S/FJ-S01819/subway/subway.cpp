#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define PII pair<int,int>
const int N=502,M=5e5+10;
int c,n,m,d,q,x,y,w[M],a[N][N],t[N][N],k[N];
vector<PII>g[M];
int dis[M],st[M];
void dij(){
	priority_queue<PII,vector<PII>,greater<PII> >q;
	dis[x]=0;
	q.push({dis[x],x});
	while(q.size()){
		PII t=q.top();q.pop();
		int u=t.second;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first,w=g[u][i].second;
			if(st[v])continue;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				st[u]=1;
				q.push({dis[v],v});
			}
		}
	}
	cout<<dis[y]+w[x]+w[y]<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int u=1;u<=k[i];u++){
			for(int v=u+1;v<=k[i];v++){
				int x=a[i][u],y=a[i][v];
				g[x].push_back({y,t[i][u]+t[i][v]});
				g[y].push_back({x,t[i][u]+t[i][v]});
			}
		}
	}
	while(q--){
		memset(dis,0x3f,sizeof dis);
		memset(st,0,sizeof st);
		cin>>x>>y;
		dij();
	}
	return 0;
}
