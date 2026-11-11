//GZ-S00165 遵义市第四中学 杨子腾 
#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
#define ll long long
ll x[N];
int c[N], d[N];
vector<int> e[N];
queue<int> q;
int topo(int u) {
	q.push(u), memset(c, 0, sizeof(c)), memset(d, 63, sizeof(d)), d[u] = 0, c[u] = 1;
	int ans = 0;
	while (q.size()) {
		int x = q.front();
		q.pop();
		if (c[x] == 2)ans++;
		for (auto i : e[x])
			if (d[i] > d[x] + 1)d[i] = d[x] + 1, c[i] = c[x], q.push(i);
			else if (d[i] == d[x] + 1)c[i] += c[x];
	}
	return ans;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, ans = 0;
		ll d;
		cin >> n >> d;
		for (int i = 1;i <= n;i++) {
			cin >> x[i], e[i].clear();
			for (int j = i - 1;j;j--)
				if (x[i] - x[j] <= d)e[j].push_back(i);
				else break;
		}
		for (int i = 1;i <= n;i++)ans += topo(i);
		cout << ans << '\n';
	}
	return 0;
}
