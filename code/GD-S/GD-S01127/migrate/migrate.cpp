#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
using ll=long long;
ll n,d;
ll s[N];
ll dp[5010][5010];
void solve(){
	ll ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dp[i][j]=1e9+10;
		dp[i][i]=0;
	}
	ll tto;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			tto=lower_bound(s+1,s+n+1,s[j]-d)-s;
			dp[i][j]=dp[i][max(tto,i)]+1;
			tto=upper_bound(s+1,s+n+1,s[i]+d)-s-1;
			int m=dp[min(tto,j)][j]+1;
			if(m==dp[i][j])ans++;
			dp[i][j]=min(m,dp[i][j]);
		}
	}
	cout<<ans<<"\n";
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c>10)cout<<-1;
	while(t--)solve();
}
