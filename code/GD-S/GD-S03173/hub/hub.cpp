#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
int fa[4005],dp[4005][4005];
bool vis[4005];
vector<int> g[4005];
int get(int x){
	if(fa[x]==x) return x;
	else return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	x=get(x);
	y=get(y);
	if(x!=y){
		fa[x]=y;
	}
}
void f(int a[]){
	int maxx=0;
	set<int> se;
	for(int i=1;i<=k;i++) se.insert(a[i]);
	memset(dp,0x3f3f3f3f,sizeof dp);
	for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			dp[i][g[i][j]]=1;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(!se.count(i) && !se.count(j) && !se.count(k)){
					dp[i][j]=max(dp[i][j],dp[i][k],dp[k][j]);
					iif(i!=j && dp[i][j!=0x3f3f3f3f )maxx=max(maxx,dp[i][j]))
				};
			}
		}
	}
	ans=min(ans,maxx);
}
void dfs(int u,int a[]){
	if(u>k){
		set<int> se;
		for(int i=1;i<u;i++){
			se.insert(get(a[i]));
		}
		if(se.size()<=2){
			f(a);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			int b[4005];
			for(int j=1;j<u;j++){
				b[j]=a[j];
			}
			b[u]=i;
			dfs(u+1,b);
			vis[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_baczk(v);
			g[v].push_back(u);
			merge(u,v);
		}
	    int a[4005];
	    dfs(1,a);
	    cout<<ans<<endl;
	} 
	return 0;
}
