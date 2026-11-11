#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int C,n,m,x[N],d[N],s,cnt,now,ans;
vector<int>ed[N];
void add(int u,int v){
	ed[u].push_back(v),ed[v].push_back(u);
}
void dfs1(int u,int fa,int dep){
	int f=dep;
	if(x[u])d[u]=0,dep=0;
	for(auto v:ed[u])
		if(v!=fa){
			dfs1(v,u,dep+1);d[u]=min(d[u],d[v]+1);
			if(!x[u]&&x[v])
				s++;
		}
	now=max({now,f,d[u]});
}
void check(){
	s=x[1],now=0,dfs1(1,0,0);
	if(s<=2&&cnt==m)
		ans=min(ans,now);
}
void dfs1(int u){
	if(u>n)return check();
	x[u]=1,cnt++,dfs1(u+1),x[u]=0,cnt--,dfs1(u+1);
}
void solve(){
	cin>>n>>m,ans=n;
	for(int i=1;i<=n;i++)
		ed[i].clear();
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,add(u,v);
	if(C<=3)dfs1(1);
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>C>>T;
	while(T--)solve();
	return 0;
}
