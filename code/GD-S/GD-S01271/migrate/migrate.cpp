#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int M=2e5;
using ll=long long;
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
ll dp[N][N]; 
ll shor[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll a[M];
		ll n,d;
		cin>>n>>d;
		if(n<=N){
			for(ll i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=N;i++){
				shor[i]=5005;
			}
			shor[1]=0;
			dp[1][0]=0;
			for(ll i=1;i<=n;i++){
				for(ll j=1;j<i;j++){
					if(a[i]-a[j]<=d){
						shor[i]=min(shor[j]+1,shor[i]);
						//cout<<i<<" "<<shor[i]<<endl;
						dp[i][shor[j]+1]++;
					}
				}
			}
			ll ans=0;
			for(ll i=1;i<=n;i++){
			//	cout<<i<<" "<<shor[i]<<endl;
				if(dp[i][shor[i]]==2){
					ans++;
				}
			}
			cout<<ans;
			memset(dp,0,sizeof(dp));
		}else{
			for(ll i=1;i<=n;i++){
				cin>>a[i];
			}
			ll len=a[n]-a[1];
			ll k=len/(n-1);
			ll u=d/k;
			ll ans=0;
			for(ll i=1;i*u+2<=n;i++){
				ans+=n-(i*u+1);
			}
			cout<<ans<<endl; 
		}
	}
} 
