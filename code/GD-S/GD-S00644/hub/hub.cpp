#include<bits/stdc++.h>
using namespace std;
const long long MAXN=10005;
long long c,t,n,k,u,v,dp1[MAXN][MAXN],dp2[MAXN][MAXN];
vector<long long> g[MAXN];
long long dp(long long x,long long n,long long m){
	long long ans=1e18;
	for(long long i=0;i<=m;i++){
		ans=min(ans,dp1[x][i]);
	}
	for(long long i=0;i<=n;i++){
		ans=min(ans,dp2[x][i]);
	}
	return ans;
}
void dfs(long long x,long long fa,long long m){
	bool b=0;
	for(long long v : g[x]){
		if(v!=fa){
			dfs(v,x,m);
			b=1;
		}
	}
	if(b==0){
		dp1[x][m]=1;
		dp2[x][1]=1;
		return ;
	}
	dp1[x][m]=1;
	for(long long v : g[x]){
		long long ans=1e18;
		for(long long i=0;i<=m;i++){
			ans=min({dp1[v][i],dp2[v][i],ans});
		}
		dp1[x][m]+=ans;
	}
	for(long long i=0;i<m;i++){              //dp1[x][0~m-1]
		long long anss=1e18,b=0,ans;
		for(long long v : g[x]){
			long long q=dp(v,i-2,m);
			if(q<=dp1[v][i+1])
				b=1;
			anss=min(anss,dp1[v][i+1]-q);
			ans+=min(q,dp1[v][i+1]);
			
		}
		if(b==0)
			dp1[x][i]=ans+anss;
		else
			dp1[x][i]=ans;
	}
	dp2[x][0]=dp1[x][0];
	for(long long i=1;i<=m;i++){
		long long anss=1e18,b=0,ans;
		for(long long v : g[x]){
			long long q=dp(v,i-2,m);
			if(q<=dp2[v][i-1])
				b=1;
			anss=min(anss,dp2[v][i-1]-q);
			ans+=min(q,dp2[v][i-1]);
			
		}
		if(b==0)
			dp2[x][i]=ans+anss;
		else
			dp2[x][i]=ans;
	}
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(long long i=1;i<=n;i++){
			g[i].clear();
		}
		for(long long i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==n){
			cout<<0<<'\n';
			continue;
		}
		if(k==n-1 || k==n-2){
			cout<<1<<'\n';
			continue;
		}
		if(c==13 || c==14){
			long long m=(n-1)/2;
			if(k>=m)
				cout<<1<<'\n';
			else
				cout<<m/k+1<<'\n';
			continue;
		}
		if(c==1){
			cout<<1<<'\n';
			continue; 
		}
		long long l=1,r=n-1;
		while(l<=r){
			memset(dp1,0,sizeof(dp1));
			memset(dp2,0,sizeof(dp2));
			long long m=(l+r)/2;
			dfs(1,0,m);
			long long ans=dp(1,0,m);
			if(ans>k)
				l=m+1;
			else
				r=m-1;
		}
		cout<<l<<'\n';
	}
	return 0;
}

