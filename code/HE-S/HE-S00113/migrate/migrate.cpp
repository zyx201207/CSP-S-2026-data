#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+100;
int c,t;
int x[N];
int dp[N];
int n,d;
int ans = 0;
int sum = 0;
inline void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	ans = 0;
	for(int i=4;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			sum = 0;
			if(x[j+i-1] - x[j]>d&&x[j+i-1] - x[j]<2*d){	
				for(int l=j+1;l<j+i-1;l++){
					if(x[l] - x[j] <= d&&x[n-i+1] - x[l] <= d){
						sum+=1;
					}
				}
			}
		//	cout<<sum<<"\n";
			if(sum == 2){
				ans += 1;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
}
