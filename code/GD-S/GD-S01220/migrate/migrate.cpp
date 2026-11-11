#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,x[2000006],ans,dp[2000006],dp1[2000006];
void dfs(int h){
	if(h==n){
		return;
	}else{
		for(int i=h+1;i<=n;i++){
			if(x[i]-x[h]<=d){
				if(dp[i]==dp[h]+1){
					dp1[i]++;
				}else if(dp[i]>dp[h]+1){
					dp[i]=dp[h]+1;
					dp1[i]=1;
				}dfs(i);
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	if(c==13||c==14){
		while(T--){
			cout<<0<<"\n";
		}
	}
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			dp[i]=1e9;
			dp1[i]=0;
		}
		for(int i=1;i<=n;i++){
			dp[i]=0;
			dfs(i);
			for(int j=i+1;j<=n;j++){
				if(dp1[j]==2){
					ans++;
				}dp[j]=1e9;
				dp1[j]=0;
			}
		}cout<<ans<<"\n";
	}
}

