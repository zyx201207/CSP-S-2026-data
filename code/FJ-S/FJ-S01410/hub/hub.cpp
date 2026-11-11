#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int c,t,n,k,tmp1,tmp2,ans,dist[1010][1010],vis2[1010];
bitset<MAXN> vis;
vector<int> edge[MAXN];
void dfs3(int x,int fa){
	vis2[x] = 1;
	for(int i = 0;i<edge[x].size();i++){
		int to = edge[x][i];
		if(to==fa) continue;
		if(vis[to]!=1) continue;
		dfs3(to,x);
	}
}
bool check(){
	int cnt = 0;
	for(int i = 0;i<=n;i++) vis2[i] = 0;
	for(int i = 1;i<=n;i++){
		if(!vis2[i] && vis[i]){
			cnt++;
			dfs3(i,-1);
		}
	}
	//cout << cnt << '\n';
	return cnt<=2;
}
void dfs(int dep,int cnt){
	if(cnt>k) return;
	if(cnt+n-dep+1<k) return;
	if(dep==n+1){
		//cout << cnt;
		if(!check()) return;
		int res = 0;
		for(int i = 1;i<=n;i++){
			int minn = 1e9;
			for(int j = 1;j<=n;j++)
				if(vis[j]==1) minn = min(minn,dist[i][j]);
			res = max(res,minn);
		}
		//cout << res;
		ans = min(ans,res);
		return;
	}
	vis[dep] = 1;
	dfs(dep+1,cnt+1);
	vis[dep] = 0;
	dfs(dep+1,cnt);
}
void dfs2(int x,int fa,int zx,int dep){
	dist[zx][x] = dep;
	for(int i = 0;i<edge[x].size();i++){
		int to = edge[x][i];
		if(to==fa) continue;
		dfs2(to,x,zx,dep+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		ans = 1e9;
		cin >> n >> k;
		for(int i = 0;i<=n;i++) edge[i].clear();
		for(int i = 1;i<n;i++){
			scanf("%d %d",&tmp1,&tmp2);
			edge[tmp1].push_back(tmp2);
			edge[tmp2].push_back(tmp1);
		}
		for(int i = 1;i<=n;i++) dfs2(i,-1,i,0);
		dfs(1,0);
		cout << ans << '\n';
	}
	return 0;
}
