#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int x[N], f[N], cnt[N];
void solve(int c) {
	int n, d; cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> x[i];
	if(c == 11 || c == 12) {
		vector<int> kkk;
		int ans = 0;
		for(int i = 1; i <= n; i++) if(x[i] > x[1] + d && x[i] == x[1] + 2 * d - 1) kkk.push_back(x[i] - x[1]);
		if(kkk.empty()) {
			cout << 0 << "\n";
			return;
		}
		for(int i = 1; i <= n; i++) {
			if(kkk.back() + x[i] <= x[n]) ans += kkk.size();
			else{
				int kkkk = upper_bound(kkk.begin(), kkk.end(), x[n] - x[i]) - kkk.begin();
				ans += kkkk;
			}
		}
		cout << ans << "\n";
		return;
	}
	deque<int> q;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		q.clear();
		f[i] = 0; cnt[i] = 1;
		q.push_back(i);
		for(int j = i + 1; j <= n; j++) {
			while(!q.empty() && x[q.front()] + d < x[j]) q.pop_front();
//			cout << "q: ";
//			for(auto xx : q) cout << xx << " ";
//			cout << "\n";
			if(q.empty()) break;
			f[j] = f[q.front()] + 1;
			if(q.size() >= 3 && f[q[1]] == f[q[0]] && f[q[2]] == f[q[0]]) cnt[j] = 3;
			else if(q.size() >= 2 && f[q[1]] == f[q[0]] && cnt[q[0]] + cnt[q[1]] > 2) cnt[j] = 3;
			else if(q.size() >= 2 && f[q[1]] == f[q[0]]) cnt[j] = cnt[q[0]] + cnt[q[1]];
			else cnt[j] = cnt[q.front()];
			if(cnt[j] == 2) ans++;
			while(!q.empty() && f[q.back()] > f[j]) q.pop_back();
			q.push_back(j);
		}
		//cout << cnt[n];
		//cout << "\n";
	}
	cout << ans << "\n";
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t; cin >> c >> t;
	while(t--) solve(c);
	return 0;
}