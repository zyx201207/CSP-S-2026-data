#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
int n,k,h[N],to[N],nt[N],tot,dp[N],ans,v[N],vv[N];
void add(int x,int y){
	to[++tot]=y;
	nt[tot]=h[x];
	h[x]=tot;
}
void dfs2(int x,int fa,int k){
	dp[x]=min(dp[x],k);
	if(!k)v[x]=0;
	for(int i=h[x];i;i=nt[i]){
		if(to[i]!=fa){
			dfs2(to[i],x,k+(v[to[i]]^1));
		}
	}
}
void dfs(int i,int s){
	if(s>k)return;
	if(i>n){
		if(s==k){
			int sum=0;
			for(int i=1;i<=n;i++){
				dp[i]=n;
			}
			for(int i=1;i<=n;i++)vv[i]=v[i];
			for(int i=1;i<=n;i++){
				if(v[i]){
					sum++;
					dfs2(i,0,0);
				}
			}
			for(int i=1;i<=n;i++)v[i]=vv[i];
			int mx=0;
			if(sum<=2){
				for(int i=1;i<=n;i++){
					mx=max(mx,dp[i]);
				}
				ans=min(ans,mx);
			}
		}
		return;
	}
	v[i]=1;
	dfs(i+1,s+1);
	v[i]=0;
	dfs(i+1,s);
}
void solve(){
	cin>>n>>k;
	tot=0;
	for(int i=1;i<=n;i++)h[i]=0;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	ans=n;
	dfs(1,0);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
}
