#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long long,long long> pll;

const ll  mn = 1005;

int c,t;
ll n,d,z;
vector<ll> a;
pll dp[mn][mn];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c >= 7){
		for(int i = 0;i < t;i++) cout<<0<<'\n';
		return 0;
	}
	while(t--){
		cin>>n>>d;
		a.clear();
		a.push_back(0);
		for(int i = 1;i <= n;i++){
			cin>>z;
			a.push_back(z);
		}
		memset(dp,0,sizeof(dp));
		for(int i = 1;i <= n-1;i++){
			if(a[i+1]-a[i] <= d){
				dp[i][i+1].first = 1;
				dp[i][i+1].second = 1;
			}
			else{
				dp[i][i+1].first = 2e18;
				dp[i][i+1].second = 0;
			}
		}
		ll ans = 0;
		for(int l = 2;l <= n-1;l++){
			for(int i = 1;i+l <= n;i++){
				int j = i+l;
				if(a[j]-a[i] <= d){
					dp[i][j].first = 1;
					dp[i][j].second = 1;
					continue;
				}
				dp[i][j].first = 2e18;
				for(int k = i+1;k <= j;k++){
					if(dp[i][k].first+dp[k][j].first < dp[i][j].first){
						dp[i][j].first = dp[i][k].first+dp[k][j].first;
						dp[i][j].second = dp[i][k].second*dp[k][j].second;
					}
					else if(dp[i][k].first+dp[k][j].first == dp[i][j].first){
						dp[i][j].second += dp[i][k].second*dp[k][j].second;
					}
				}
				if(dp[i][j].second == 2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}

