#include <iostream>
#include <cstring>
#include <cctype>
#include <queue>
#define int long long
using namespace std;

const int MXN = 2e6 + 5;
int c, t, n, d, ans, x[MXN];

void Task1(){
	static int len[5005], cnt[5005];
	queue<int> q;
	ans = 0;
	for (int u0 = 1; u0 <= n; u0 += 1){
		memset(len, 0x3f, sizeof(len));
		memset(cnt, 0, sizeof(cnt));
		q.push(u0);
		len[u0] = 0, cnt[u0] = 1;
		while (!q.empty()){
			int u = q.front(); q.pop();
			if (cnt[u] == 2) ans += 1;
			for (int v = u + 1; v <= n && x[v] - x[u] <= d; v += 1){
				if (len[u] + 1 > len[v]) continue;
				else if (len[u] + 1 == len[v]) cnt[v] += cnt[u];
				else len[v] = len[u] + 1, cnt[v] = cnt[u], q.push(v);
			}
		}
	}
	return;
}

void Task2(){
	int s = d / (x[2] - x[1]);
	if (s >= 2) ans = max(n - 2 * s + 1, 0ll);
	else ans = 0;
	return;
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i = 1; i <= n; i += 1) cin >> x[i];
		if (1 <= c && c <= 10) Task1();
		else if (11 <= c && c <= 12) Task2();
		cout << ans << '\n';
	}
	
	return 0;
}
