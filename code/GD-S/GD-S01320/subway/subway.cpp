#include<bits/stdc++.h>
#define PII pair<int,int>
#define int long long
using namespace std;
const int N=5e5+10,inf=0x3f3f3f3f3f3f3f3f,M=510;
int k,tsk,n,m,d,q,w[N],a[N],t[N],cnt,x,y;
priority_queue<PII,vector<PII>,greater<PII> > p;
map<PII,int> mp;
vector<PII> g[N];
void dijsktra(int s,int t){
	while(!p.empty())p.pop();
	for(int i=1;i<=cnt;i++)mp[{s,i}]=inf;
	p.push({0,s}),mp[{s,s}]=0;
	while(!p.empty()){
		auto k=p.top();p.pop();
		int w=k.first,u=k.second;
		if(w>mp[{s,u}])continue;
		for(auto it:g[u]){
			int v=it.first,ww=it.second;
			if(mp[{s,v}]>w+ww)mp[{v,s}]=mp[{s,v}]=w+ww,p.push({mp[{s,v}],v});
		}
	}
}
void add(int x,int y,int w){
	g[x].push_back({y,w}),
	g[y].push_back({x,w});
//	cout<<x<<' '<<y<<' '<<w<<'\n';
}
int c[M][M],ans;
vector<int> h[N];
void sol(){
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)cin>>a[j]>>t[0],h[a[j]].push_back(i);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)c[i][j]=inf;
	for(int i=1;i<=n;i++)c[i][i]=0;
	for(int i=1;i<=m;i++)for(int j:h[i])for(int k:h[i])c[j][k]=c[k][j]=min(c[j][k],1ll);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++)c[j][k]=min(c[j][k],c[j][i]+c[i][k]);
		}
	}
	while(q--){
		cin>>x>>y,ans=inf;
		for(int u:h[x])for(int v:h[y]){
//			cout<<u<<' '<<v<<' '<<c[u][v]<<'\n';
			ans=min(ans,c[u][v]);
		}
		cout<<(ans+1)*2*t[0]+w[x]+w[y]<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>tsk>>n>>m>>d>>q,cnt=m;
	if(tsk>=12&&tsk<=19){
		sol();
		return 0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)cin>>a[j]>>t[j];
		add(++cnt,a[1],t[1]);
		for(int j=2;j<=k;j++){
			add(++cnt,a[j],t[j]), 
			add(cnt-1,cnt,0);
		}
	}
	while(q--){
		cin>>x>>y;
		if(!mp.count({x,y}))dijsktra(x,y);
		cout<<w[x]+w[y]+mp[{x,y}]<<'\n';
	}
}
/*
12 3 6 20 10
1 2 3 4 5 6
4 1 1 2 1 3 1 4 1
4 2 1 3 1 4 1 5 1
4 3 1 4 1 5 1 6 1
1 2
2 3
3 4
4 5
5 6
1 4
1 5
1 6
3 5
3 6
*/
