#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=3e6;
ll dp[N],a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll c,t;
	cin>>c>>t;
	dp[1]=1;
	while(t--){
		ll n,d,sum=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>a[i];
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d&&j-i>=2) dp[j]=dp[i]+1;
			}
		}
		for(ll i=1;i<=n;i++){
			if(dp[i]==2) sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
