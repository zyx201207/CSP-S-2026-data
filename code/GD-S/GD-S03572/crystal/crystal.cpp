#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005],b[500005];
ll dp[5005][5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>5000){
		b[1]=0;
		for(int i=2;i<=n;i++){
			b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
			if(b[i]>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
	}else{
		ll ans=0;
		for(int i=1;i<=n;i++){
			dp[i][i]=0;
			for(int j=i+1;j<=n;j++){
				dp[i][j]=(a[j]-a[j-1])*(j-i)+dp[i][j-1];
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(dp[i][j]<=m){
					ans=max(ans,j-i+1);
				}
			}	
		}
		cout<<ans;
	}
	
	return 0;
}
