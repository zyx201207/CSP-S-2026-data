#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
const int M = 5e5 + 5;
int v[M];
struct station {
    int path[25];
    int ti[25];
    int cnt;
} a[M];
struct sline {
    vector <pair <int, int>> node;
} b[N];
ll dp[N][N];
int c, n, m, d, q;
void floyd_work() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    return ;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
        cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        while (num--) {
            int x, t;
            cin >> x >> t;
            a[x].cnt++;
            a[x].path[a[x].cnt] = i;
            a[x].ti[a[x].cnt] = t;

            b[i].node.push_back(make_pair(x, t));
        }
	}
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
        for (pair <int, int> pii : b[i].node) {
            int j = pii.first;
            ll t_ij = pii.second;
            for (int k = 1; k <= a[j].cnt; k++) {
                ll t_ijk = t_ij + a[j].ti[k];
                int arrive = a[j].path[k];
                ll Update_dp = min(dp[arrive][i], t_ijk);
                dp[arrive][i] = dp[i][arrive] = Update_dp;
            }
        }
	}
    floyd_work();
    while (q--) {
        int x, y;
        cin >> x >> y;
        ll ans = 1e18;
        for (int i = 1; i <= a[x].cnt; i++) {
            for (int j = 1; j <= a[y].cnt; j++) {
                ans = min(ans, dp[a[x].path[i]][a[y].path[j]] + (long long)(a[x].ti[i]) + (long long)(a[y].ti[j]));
            }
        }
        cout << ans + v[x] + v[y] << "\n";
    }
	return 0;
}
/*
O(sum(k)*d+q*d*d)
*/
