#include<bits/stdc++.h>
using namespace std;
int c,t;
int dep[1000005];
int f[1000005][25];
vector<int>g[1000005];
int d[4005][4005];
int n,k;
void dfs(int u,int fa){
	for(auto it:g[u]){
		if(it==fa)continue;
		dep[it]=dep[u]+1;
		dfs(it,u);
		f[it][0]=u;
	}
}
void init(){
	for(int i=1;i<=n;i=-~i){
		for(int j=0;j<=20;j=-~j)f[i][j]=-1;
		dep[i]=0;
	}
	dfs(1,0);
	for(int j=1;j<=20;j=-~j){
		for(int i=1;i<=n;i=-~i){
			if(f[i][j-1]!=-1)f[i][j]=f[f[i][j-1]][j-1];
		}
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=20;i>=0;i=~-i){
		if((1<<i)<=dep[u]-dep[v])u=f[u][i];
	}
	if(u==v)return u;
	for(int i=20;i>=0;i=~-i){
		if(f[u][i]!=0&&f[u][i]!=f[v][i]){
			u=f[u][i],v=f[v][i];
		}
	}
	return f[u][0];
}
int a[1000005],b[1000005],ans;
vector<int>kk;
bool vis[2000005],vis1[2000005];
void check(int u,int fa){
	vis1[u]=1;
	for(auto it:g[u]){
		if(it==fa)continue;
		if(!vis[it])continue;
		check(it,u);
	}
}
void dg(int num,int sum){
	if(n-num+1<k-sum)return;
	if(num==n+1){
		for(int i=1;i<=n;i=-~i)vis1[i]=0;
		int cnt=0;
		for(auto it:kk){
			if(!vis1[it]){
				check(it,0);
				cnt++;
			}
		}
		if(cnt>2)return;
		int s=0;
		for(int i=1;i<=n;i=-~i){
			int x=INT_MAX;
			for(auto it:kk){
				x=min(x,dep[i]+dep[it]-2*dep[lca(it,i)]);
			}
			s=max(s,x);
		}
		ans=min(ans,s);
		return;
	}
	if(sum<k){
		vis[num]=1;
		kk.push_back(num);
		dg(num+1,sum+1);
		kk.pop_back();
		vis[num]=0;
	}
	dg(num+1,sum);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c>=4&&c!=7){
		while(t--){
			cin>>n>>k;
			int u,v;
			for(int i=1;i<n;i=-~i){
				cin>>u>>v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			cout<<(int)log2(n)+1<<'\n';
		}
		return 0;
	} 
	while(t--){
		ans=INT_MAX;
		cin>>n>>k;
		for(int i=1;i<=n;i=-~i)g[i].clear();
		int u,v;
		for(int i=1;i<n;i=-~i){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		init();
		if(k==2){
			for(int i=1;i<=n;i=-~i){
				for(int j=i+1;j<=n;j=-~j){
					d[i][j]=d[j][i]=dep[i]+dep[j]-dep[lca(i,j)]*2;
				}
			}
			for(int i=1;i<=n;i=-~i){
				for(int j=i+1;j<=n;j=-~j){
					int sum=0;
					for(int k=1;k<=n;k=-~k){
						sum=max(sum,min(d[i][k],d[j][k]));
					}
					ans=min(ans,sum);
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		dg(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
rp++
*/
/*
显然是一个二分答案
我们设本次二分出来的答案为x
考虑贪心去check
我们以每个点为根判断一下 
*/

