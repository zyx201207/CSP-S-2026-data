#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int a[N],dp[N];
void solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i-1]-a[j]!=a[i]-a[i-1]&&a[i-1]-a[j]<=d&&a[i]-a[j]>d){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
} 
