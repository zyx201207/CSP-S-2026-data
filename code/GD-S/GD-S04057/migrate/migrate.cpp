#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t,tot=1,f[20005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll n,d,a[200005],dp[200005][200005],cnt=0;
		ll method;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		} 
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(i==j)continue;
				if(abs(i-j)==1)dp[i][j]=a[j]-a[j-1]>d?-1:1;
				method=1;
				for(ll k=1;k<=d;k++){
					if(i!=j-k){
						if(dp[i][j]==dp[i][j-k]+1){
							method++;
						}
						dp[i][j]=min(dp[i][j-k]+1,dp[i][j]);
					}
				}
				cnt+=method==2;
			}
		}
		f[tot]=cnt;
		tot++;
	}
	for(int i=1;i<tot;i++){
		cout<<f[i];
	}
	return 0;
}
