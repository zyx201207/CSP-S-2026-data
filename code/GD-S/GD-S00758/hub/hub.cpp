#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define zzz ios::sync_with_stdio(0),cin.tie(0)
#define e_b emplace_back
using namespace std;
const int N=1005,inf=1e9;
vector<int>t[N];
int ans;
int fa[N];
int find(int x){return fa[x]=x^fa[x]?find(fa[x]):x;}
int g[N][N],dis[N][N];
int n,k;
int s[N];
void dfs1(int rt,int u,int fa){
	for(int v:t[u])if(v^fa){
		dis[rt][v]=dis[rt][fa]+1;
		dfs1(rt,v,u);
	}
}
void dfs(int u,int x){
	if(u>n)return;
	if(x==k){
		for(int i=1;i<=k;i++)fa[s[i]]=s[i];
		for(int i=1;i<=k;i++)
			for(int j=i+1;j<=k;j++){
				int u=find(s[i]),v=find(s[j]);
				if(g[s[i]][s[j]])if(u^v)fa[v]=u;
			}
		int c=0;
		for(int i=1;i<=k;i++)if(fa[s[i]]==s[i])c++;
		if(c>2)return;
		int re=0;
		for(int i=1;i<=n;i++){
			int mi=inf;
			for(int j=1;j<=k;j++)mi=min(mi,dis[i][s[j]]);
			re=max(re,mi);
		}
		ans=min(ans,re);
	}
	s[x+1]=u;dfs(u+1,x+1);
	dfs(u+1,x);
}
void solve(){
	cin>>n>>k;ans=inf;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(i^j)g[i][j]=0,dis[i][j]=inf;
		t[i].clear();
	}
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v,g[u][v]=g[v][u]=1;
		t[u].e_b(v),t[v].e_b(u);
	}
	if(k==n){cout<<"0\n";return;}
	for(int i=1;i<=n;i++)dfs1(i,i,i);
	dfs(1,0);
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	zzz;int c,T;cin>>c>>T; 
	while(T--)solve();
}
/*
找到直径
涂上直径中点
找到深度最大的子树 
 
*/ 

