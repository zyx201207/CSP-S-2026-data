#include<bits/stdc++.h>
using namespace std;
#define int long long
int T=1,c,n,d,ans=0,cnt=0;
int x[2000005];
int dp[2000005];

void dfs(int l,int r,int t,int m){
	if(l==r&&t==m){
		cnt++;
		return ;
	}else if(l>r||t>m){
		return ;
	}
	for(int i=l+1;x[i]-x[l]<=d;i++){
		dfs(i,r,t+1,m);
	}
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			for(int p=1;p<=n;p++)dp[p]=1e18;
			dp[i]=0;
			cnt=0;
			for(int k=i+1;k<=j;k++){
				for(int h=k-1;h>=i;h--){
					if(x[k]-x[h]<=d)
						dp[k]=min(dp[k],dp[h]+1);
				}
			}
			dfs(i,j,0,dp[j]);
			if(cnt==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
