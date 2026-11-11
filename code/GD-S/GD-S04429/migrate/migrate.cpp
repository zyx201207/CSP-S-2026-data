#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	cin >> t;
	while(t--) {
		vector<pair<int,int>>dp;//step with plan_num
		vector<int>a;
		vector<int>d;
		int n,k,ans = 0;
		cin >> n >> k;
		a.resize(n+1);
		dp.resize(n+1);
		d.resize(n+1);
		for(int i=1; i<=n; i++) {
			cin >> a[i];
			d[i] = a[i] - (i-1?a[i-1]:a[i]);
		}
		deque<pair<int,int>>q;//step now
		q.push_back({0,0});
		while(!q.empty()) {
			pair<int,int> t = q.front();
			q.pop_front();
			int i = t.second+1;
			int sum = d[i];
			while(sum<=k&&i<=n) {
				if(dp[i].first&&t.first+1>dp[i].first) {
					q.push_back({t.first+1,i});
					i++,sum+=d[i];
					continue;
				}
				if(t.first+1==dp[i].first)dp[i].second++;
				else dp[i].first = t.first+1,dp[i].second = 1;
				q.push_back({t.first+1,i});
				i++,sum+=d[i];
			}
		}
		for(int i=1; i<=n; i++)
			if(dp[i].second == 2)
				ans++;
		cout<<ans<<endl;
	}
	return 0;
}
