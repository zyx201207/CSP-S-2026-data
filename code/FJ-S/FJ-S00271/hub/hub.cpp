#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10005;
int c,T,n,k,x,y,ans,tot,cnt,a[N],fa[N],deep[N];
bool vis[N];
vector<int>V[N];
void dfs1(int u,int f){
	fa[u]=f;
	deep[u]=deep[f]+1;
	for(auto v:V[u])
		if(v!=f)dfs1(v,u);
} 
void dfs(int u){
	vis[u]=0;
	for(auto v:V[u])
		if(vis[v])dfs(v);
}
int dist(int x,int y){
	int res=0;
	if(deep[x]<deep[y])swap(x,y);
	while(deep[x]>deep[y])x=fa[x],res++;
	while(x!=y)x=fa[x],y=fa[y],res+=2;
	return res;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=1e18;
		cin>>n>>k;
		for(int i=1;i<=n;i++)V[i].clear();
		for(int i=1;i<n;i++){
			cin>>x>>y;
			V[x].push_back(y);
			V[y].push_back(x);
		}
		dfs1(1,0);
		for(int i=0;i<(1ll<<n);i++){
			tot=cnt=0;
			for(int j=0;j<n;j++)
				if(i&(1ll<<j))
					a[++tot]=j+1;
//			for(int j=1;j<=tot;j++)cout<<a[j]<<" ";
//			cout<<"\n";
			if(tot!=k)continue;
			for(int j=1;j<=k;j++)vis[a[j]]=1;
			for(int j=1;j<=n;j++)
				if(vis[j])dfs(j),cnt++;
			if(cnt!=2)continue;
			int maxn=0;
			for(int j=1;j<=n;j++){
				int minn=1e18;
				for(int l=1;l<=k;l++)minn=min(minn,dist(j,a[l]));
				maxn=max(maxn,minn);
			}
			ans=min(ans,maxn);	 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
