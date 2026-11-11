#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5000 + 5;

int n;
ll dp[N][N], dep[N], sum[N];
ll d, a[N];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int C, T; cin >> C >> T;
	while (T--){
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		
		int ans = 0;
		for (int st = 1; st <= n; st++){
			dp[st][0] = 1, dep[st] = 0, sum[0] = 1;
			int id = st;
			for (int i = st + 1; i <= n; i++){
				while (id < i && a[i] - a[id] > d) sum[dep[id]] -= dp[id][dep[id]], id++;
				dep[i] = dep[id] + 1;
				if (id == i) break;
				
				dp[i][dep[i]] = sum[dep[i] - 1];
				sum[dep[i]] += dp[i][dep[i]];
				if (dp[i][dep[i]] == 2) ans++;
			}
			
			for (int i = st; i <= n; i++) dp[i][dep[i]] = 0;
			for (int i = st; i <= n; i++) dep[i] = 0;
			for (int i = 0; i <= n; i++) sum[i] = 0;
		}
		cout << ans << '\n';
	}
	
	return 0;
}
