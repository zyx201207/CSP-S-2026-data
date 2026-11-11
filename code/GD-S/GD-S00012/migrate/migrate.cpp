#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ull = unsigned long long;

int fast_io = []() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	return 0;
}();

constexpr int N = 2e6;

int testcase, t;
ll n, d;
ll arr[N + 5];

ll l_max[N + 5];
ll r_max[N + 5];
ll l_uni[N + 5];
ll r_uni[N + 5];
int tong[5005][5005];
int dis[5005][5005];
vector<int> graph[5005];

void input() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}

void preinit_max() {
	int l = 1;
	for (int i = 1; i <= n; i++) {
		while (arr[i] - arr[l] > d) {
			l += 1;
		} l_max[i] = l;
	} int r = n;
	for (int i = n; i >= 1; i--) {
		while (arr[r] - arr[i] > d) {
			r -= 1;
		} r_max[i] = r;
	}
}

void preinit_uni() {
	for (int i = 1; i <= n; i++) {
		l_uni[i] = 1;
		int tmp = l_max[i];
		if (r_max[tmp] == i) {
			l_uni[i] += l_uni[tmp];
		}
	} for (int i = n; i >= 1; i--) {
		r_uni[i] = 1;
		int tmp = r_max[i];
		if (l_max[tmp] == i) {
			r_uni[i] += r_uni[tmp];
		}
	}
}

void solve_subA() {
	if (n == 1) {
		cout << 0 << '\n';
		return;
	} ll diff = arr[2] - arr[1];
	if (d < 2 * diff) {
		cout << 0 << '\n';
		return;
	} d /= diff;
	cout << max(0ll, n - d*2 + 1) << '\n'; 
}

void brute_force() {
	for (int i = 1; i <= n; i++) {
		graph[i].clear();
		for (int j = i; j <= n; j++) {
			dis[i][j] = 0x3f3f3f3f;
			tong[i][j] = 0;
		}
	} for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= r_max[i]; j++) {
			graph[i].emplace_back(j);
		}
	} for (int i = 1; i <= n; i++) {
		queue<int> q;
		dis[i][i] = 0;
		tong[i][i] = 1;
		q.push(i);
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			for (auto v: graph[t]) {
				int tmp = dis[i][t] + 1;
				if (dis[i][v] > tmp) {
					dis[i][v] = tmp;
					tong[i][v] = tong[i][t];
					q.push(v);
				} else if (dis[i][v] == tmp) {
					tong[i][v] += tong[i][t];
					if (tong[i][v] > 2) tong[i][v] = 3;
				}
			}
		}
	} int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (tong[i][j] == 2) {
				ans += 1;
			}
		}
	} cout << ans << '\n';
}

void solve_subB() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int r_id = r_max[i];
		int rr_id = r_max[r_id];
		int r2_id = r_id - 1;
		int nr_id = r_max[r2_id];
		int r3_id = r2_id - 1;
		
		if (r_id == n) {
			break;
		} if (r2_id <= i) {
			continue;
		} if (rr_id <= r_id) {
			continue;
		}
		
		if (r3_id <= i) {
			if (rr_id == nr_id) {
				ans += 1;
			} int xx = rr_id-1;
			if (xx <= r_id) continue;
			if (xx <= nr_id) {
				ans += 1;
			}
		} else {
			int xx = rr_id;
			if (nr_id == xx && xx > r_max[r3_id]) {
				ans += 1;
			} xx -= 1;
			if (nr_id >= xx && xx > r_max[r3_id]) {
				ans += 1;
			}
		}
	} cout << ans << '\n';
}

void solve() {
	memset(l_max, 0, sizeof(ll) * (n + 1));
	memset(r_max, 0, sizeof(ll) * (n + 1));
	preinit_max();
	preinit_uni();
	
	if (testcase <= 10) {
		brute_force();
	} else if (testcase == 11 || testcase == 12) {
		solve_subA();
	} else if (testcase == 13 || testcase == 14) {
		solve_subB();	
	} else cout << 0 << '\n';
}

int main() {
	cin >> testcase >> t;
	while (t--) {
		input();
		solve();	
	} cout << flush;
	return 0;
}
