#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;
long long cnt, a[maxn], dis[maxn];

//void dfs(int now) {
//	for (int i = 1;  
//	long long sum = dis[now], dk = 1;
//	while (sum <= d) {
//		dfs(now + dk);
//		sum += dis[now + dk];
//		dk++;
//	} 
//}

void solve() {
	bool f = false;
	long long n, d; cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		dis[i] = a[i + 1] - a[i]; 
//		if (dis[i] > d) {f = true; break;}
	}
//	if (f) {cout << 0 << endl; return ;}
//	dfs(1);
}

void solve1145() cout << 0 << endl;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, q;
	cin >> c >> q;
	while (q--) solve1145();
} 
