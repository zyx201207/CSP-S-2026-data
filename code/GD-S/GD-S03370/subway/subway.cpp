#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,inf=1e18;
int n,m,d,q,vis[505],w[N],dis[505],F[505][505];
vector<pair<int,int>>g[505],s[N];
void sol(int id){
	priority_queue<pair<int,int>>Q;
	for(int i=1;i<=n;i++)dis[i]=inf;
	for(int i=1;i<=n;i++)vis[i]=0;
	Q.push({0,id});dis[id]=0;
	while(Q.size()){
		int x=Q.top().second;Q.pop();
		if(vis[x])continue;vis[x]=1;
		for(auto[t,w]:g[x]){
			if(dis[t]>dis[x]+w){
				dis[t]=dis[x]+w;
				Q.push({-dis[t],t});
			}
		}
	}
	for(int i=1;i<=n;i++)F[id][i]=dis[i];
}
void chkmn(int&x,int y){x=(x<y?x:y);}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)F[i][j]=inf;
	for(int i=1,x,t,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>x>>t,s[x].push_back({i,t}); 
	}
	for(int i=1;i<=m;i++)
		for(auto[x1,v1]:s[i])
			for(auto[x2,v2]:s[i])
				F[x1][x2]=min(F[x1][x2],v1+v2);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i].push_back({j,F[i][j]});
	for(int i=1;i<=n;i++)sol(i);
	for(int i=1,x,y,ans;i<=q;i++){
		cin>>x>>y;ans=inf;
		for(auto[x1,v1]:s[x])
			for(auto[x2,v2]:s[y])
				chkmn(ans,F[x1][x2]+v1+v2);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
