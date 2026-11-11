#include<bits/stdc++.h>

using namespace std;

int c, t, n, d;
vector<int> g;

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		g.clear();
		g.resize(n);
		for(int i = 0;i < n;i++){
			cin>>g[i];
		}
		int x = n % d;
		if(x == 0){
			cout<<0;
			continue;
		}
		int dp[n] = {};
		dp[0] = 1;
		int ans = 0;
		for(int i = 1;i < n;i++){
			for(int j = i;j >= 0;j--){
				if(abs(g[i] - g[j]) <= d){
					dp[i] = min(dp[i] + dp[j], dp[j]);
				}
				else break;
			}
			if(dp[i] == 2){
				ans++;
			}
		}
		cout<<ans;
	}
}
