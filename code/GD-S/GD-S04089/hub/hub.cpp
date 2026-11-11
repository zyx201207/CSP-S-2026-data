#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,D,rs,vis[1000005],mx[1000005],dp[1000005],fd[1000005],f[1000005],zd[1000005],hf[1000005];
vector<int> g[1000005];
void dfs(int u,int fa){
	f[u]=fa;
	for (int v:g[u]){
		if (v==fa) continue;
		dfs(v,u);
		dp[v]=dp[u]+1;
	}
}
void dfs1(int u,int fa,int yd){
	vis[u]=1;
	if (yd==0) return ;
	for (int v:g[u]){
		if (v==fa) continue;
		dfs1(v,u,yd-1);
	}
}
void dfs2(int u){
	mx[u]=-1145141919;
	int ct=0;
	for (int v:g[u]){
		if (v==f[u]) continue;
		ct++;
		dfs2(v);
		mx[u]=max(mx[u],mx[v]+1);
		hf[u]|=hf[v];
	}
	if (!ct){
		if (vis[u]) mx[u]=-1145141919;
		else mx[u]=0;
	}
	if (mx[u]==D){
		rs+=!zd[u];
		zd[u]=hf[u]=1;
		mx[u]=-D;
	}
}
void dfs3(int u){
	for (int v:g[u]){
		if (v==f[u] || !hf[v]) continue;
		dfs3(v);
	}
	rs+=!zd[u];
	zd[u]=1;
}

void dfs4(int u){
	int ct=0;
	mx[u]=-1145141919;
	for (int v:g[u]){
		if (v==f[u] || zd[v]) continue;
		ct++;
		dfs4(v);
		mx[u]=max(mx[u],mx[v]+1);
		hf[u]|=hf[v];
	}
	if (!ct){
		if (vis[u]) mx[u]=-1145141919;
		else mx[u]=0;
	}
	if (mx[u]==D){
		rs+=!zd[u];
		zd[u]=hf[u]=1;
		mx[u]=-D;
	}
}
void dfs5(int u,int cl){
	int ct=0;
//	fd[u]=-1145141919;
	for (int v:g[u]){
		if (!hf[v]){
			fd[u]=max(fd[u],mx[v]);
		}
		if (v==f[u] || !hf[v]) continue;
		ct++;	
	}
	if (zd[u]){
		fd[u]=-1145141919;
	}
	if (ct>=2 || (cl && hf[u]) || fd[u]>=D){
		rs+=!zd[u];
		zd[u]=1;
	}
	for (int v:g[u]){
		fd[v]=fd[u]+1;
		if (v!=f[u] && hf[v]) dfs5(v,zd[u]);
	}
}
int ck(int DD){
	D=DD;
	for (int i=1;i<=n;i++){
		int ss=0;
		rs=1;
		zd[i]=1;
		dfs1(i,0,D);
		dfs2(i);
		dfs3(i);
		
		dfs4(1);
		dfs5(1,zd[1]);
		ss=rs;
		rs=0;
//		cout<<DD<<": ";for (int j=1;j<=n;j++) cout<<zd[j]<<" ";cout<<endl;
		for (int j=1;j<=n;j++){
			vis[j]=mx[j]=fd[j]=zd[j]=hf[j]=0;
//			vis[1000005],mx[1000005],dp[1000005],fd[1000005],f[1000005],zd[1000005],hf[1000005];
		}
//		cout<<DD<<" "<<ss<<" "<<k<<endl;
		if (ss<=k){
			return 1;
		} 
	}
	return 0;
}
void sl(){
	cin>>n>>k;
	for (int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n!=k){
		dfs(1,0);
		int l=1,r=n,ans=0;
		while (l<=r){
			int mid=l+r>>1;
			if (ck(mid)){
				r=mid-1;
				ans=mid;
			}else{
				l=mid+1;
			}
		}
		cout<<ans<<endl;
	}else{
		cout<<0<<endl;
	}
	for (int i=1;i<=n;i++){
		g[i].clear();
		f[i]=dp[i]=0;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _;
	cin>>_>>_;
	while (_--){
		sl();
	}
} 
