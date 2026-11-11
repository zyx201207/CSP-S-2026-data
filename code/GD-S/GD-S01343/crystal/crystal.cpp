#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
using ll = long long;

/*
dp [i][j] as the consume can merage the i to j max;1 
dp[0] = 1;
*/

struct af{
	ll c=0, s=0;
};


int main(){
	io;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	vector<ll>a;
	vector<af>dp;
	ll n, m;
	cin>>n>>m;
	dp.resize(n);
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	for(int i=1;i<n;i++){
		if(a[i]>a[i-1]){
			ll dt = a[i]-a[i-1];
			ll r = 0, p = 0;
			ll newc = dp[i-1].c // have used
			+(i-dp[i-1].s)*dt // up to next step use
			-(r*a[i]-p); // refuse add
			while(newc>m){
				p+=a[dp[i-1].s+r];
				r++;
				newc = dp[i-1].c // have used
				+(i-dp[i-1].s)*dt // up to next step use
				-(r*a[i]-p); // refuse add;
			}
			dp[i] = {newc, dp[i-1].s+r};
		}else{
			dp[i] = dp[i-1];
		}
	}
	ll ans = 0;
	for(int i=0;i<dp.size();i++){
		ans=max(ans, i-dp[i].s);
	}
	if(ans)cout<<ans+1;
	else cout<<0;
	return 0;
}


 
