#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+3;
int n,dp[5003][5003],f[5003][5003];
ll d,a[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==12){
			ll k=d/(a[2]-a[1]);
			if(k>1)ans=max(n-k-k+1,0ll);
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=f[i][j]=0;
		for(int l=2;l<=n;l++){
			for(int i=1,j;i+l-1<=n;i++){
				j=i+l-1;
				if(a[j]-a[i]<=d)dp[i][j]=1,f[i][j]=1;
				else{
					int k=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
					if(dp[k-2][j]!=dp[k-1][j]&&dp[k-1][j]==dp[k][j])f[i][j]=f[k-1][j]+f[k][j];
					else f[i][j]=f[k][j];
					dp[i][j]=dp[k][j]+1;
					if(f[i][j]==2)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
