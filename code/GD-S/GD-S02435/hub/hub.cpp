#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2E6+7;
int n,k,cnt;
bool vis[N];
int fa[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	fa[x]=y;
	cnt++;
}
vector<int> g[N];
int ans;
void dfs(int u,int fa,int dep){
	if(vis[u]){
		ans=min(ans,dep); 
		return;
	}
	for(int v:g[u]){
		if(v!=fa){
			dfs(v,u,dep+1);
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int res=INT_MAX;
		for(int i=0;i<(1<<n);i++){
			if(__builtin_popcount(i)!=k) continue;
			for(int j=1;j<=n;j++) fa[j]=j;
			cnt=0;
			memset(vis,0,sizeof vis);
			for(int j=1;j<=n;j++) vis[j]=(i>>j-1)&1;
			for(int j=1;j<=n;j++){
				if(vis[j]){
					for(int v:g[j]){
						if(vis[v]){
							merge(j,v);
						}
					}
				}
			}
			if(k-cnt!=2) continue;
			int cnt=0;
			for(int j=1;j<=n;j++){
				ans=INT_MAX;
				dfs(j,0,0);
				cnt=max(cnt,ans);
			}
			res=min(res,cnt);
		}
		cout << res << '\n';
	}
	return 0;
}
