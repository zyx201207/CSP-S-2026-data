#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k,u,v,ans,fa[15],depth[N],f[N][20],dis[1005][1005];
bool pd[15],vis[15];
vector<int> edge[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void dfs(int u,int fa){
	depth[u]=depth[fa]+1,f[u][0]=fa;
	for(int i = 1;i<=__lg(depth[u]);i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int v:edge[u]) if(v!=fa) dfs(v,u);
}
int LCA(int a,int b){
	if(depth[a]<depth[b]) swap(a,b);
	while(depth[a]!=depth[b]) a=f[a][__lg(depth[a]-depth[b])];
	if(a==b) return a;
	for(int i = __lg(depth[a]);i>=0;i--) if(f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
	return f[a][0];
}
void dfs2(int u,int sum){
	if(u>n){
		if(sum<k) return;
		for(int i = 1;i<=n;i++) fa[i]=i;
		for(int i = 1;i<=n;i++)
			for(int j:edge[i])
				if(pd[i]&&pd[j])
					fa[find(i)]=find(j);
		int cnt=0;
		memset(vis,0,sizeof vis);
		for(int i = 1;i<=n;i++) if(pd[i]&&!vis[find(i)]) vis[find(i)]=1,cnt++;
		if(cnt>2) return;
		int maxn=0;
		for(int i = 1;i<=n;i++){
			int minn=1e9;
			for(int j = 1;j<=n;j++) if(pd[j]) minn=min(minn,dis[i][j]);
			maxn=max(maxn,minn);
		}
		ans=min(ans,maxn);
		return;
	}
	if(sum<k) pd[u]=1,dfs2(u+1,sum+1);
	pd[u]=0,dfs2(u+1,sum);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 1;i<=n;i++) edge[i].clear();
		for(int i = 1;i<n;i++)
			cin>>u>>v,edge[u].push_back(v),edge[v].push_back(u);
		if(k==n){
			cout<<"0\n";
			continue;
		}
		if(c==13||c==14){
			n/=2,n++;
			int l=0,r=n,res;
			while(l<=r){
				int mid=l+r>>1;
				if(mid*4+k>=n) res=mid,r=mid-1;
				else l=mid+1;
			}
			cout<<res+1<<'\n';
			continue;
		}
		dfs(1,0);
		if(c<=3||c==7){
			for(int i = 1;i<=n;i++)
				for(int j = i+1;j<=n;j++)
					dis[i][j]=dis[j][i]=depth[i]+depth[j]-2*depth[LCA(i,j)];
			ans=1e9;
			if(c<=3) dfs2(1,0);
			else
				for(int i = 1;i<=n;i++)
					for(int j = i+1;j<=n;j++){
						int maxn=0;
						for(int k = 1;k<=n;k++) 
							maxn=max(maxn,min(dis[i][k],dis[j][k]));
						ans=min(ans,maxn);
					}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
