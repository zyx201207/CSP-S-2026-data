#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000005;
int n;
ll d;
ll x[N];
int dp[N];
ll ans;
void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		int flag=0;
		for(int j=i+1;j<=n;j++){
			int mn=n+5,mnc=0;
			for(int k=j-1;k>=i&&x[j]-x[k]<=d;k--){
				if(mn==dp[k]){
					mnc++;
				}
				else if(dp[k]<mn){
					mn=dp[k];
					mnc=1;
				}
			}
			if(mnc>2||mnc==0) break;
			if(mnc==2){
				if(flag) break;
				flag=1;
			}
			dp[j]=mn+1;
//			cout<<i<<" "<<j<<" "<<mn<<" "<<mnc<<"\n";
			if(mnc==2){
				ans++;
//				cout<<i<<" "<<j<<"\n";
			}
		}
		for(int j=i+1;j<=n;j++) dp[j]=0;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
