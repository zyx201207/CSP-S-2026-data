#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e6 + 10;
const int BN = 5e3 + 10;

int n; ll d, a[N];

int f[BN], pre[BN], can[BN];
int su[BN], sr[BN];

void solve1() {
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, res = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			
			if (a[i] - a[mid] <= d)
				res = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		can[i] = res;
	}
	
	int ans = 0;
	for (int i = 1; i < n; i++) {
		memset(f, 0, sizeof(f));
		memset(pre, 0, sizeof(pre));
		memset(su, 0, sizeof(su));
		
		int stop = n + 1; sr[0] = i;
		for (int j = i + 1; j <= n; j++) {
			if (a[j] - a[j - 1] > d) {
				stop = j;
				break;
			}
		}
		
		for (int j = i + 1; j < stop; j++) {
			su[j] = su[max(i, can[j])] + 1;
			sr[su[j]] = j;
//			cout << su[j] << " ";
		}
		
		f[i] = pre[i] = 1;
//		if (a[i + 1] - a[i] <= d) f[i + 1] = pre[i + 1] = 1;
		for (int j = i + 1; j < stop; j++) {
			if (can[j] == j) continue;
			f[j] = min(pre[sr[su[j] - 1]] - pre[max(i, can[j]) - 1], 3);
			pre[j] = pre[j - 1] + f[j];
		}
		
		for (int j = i + 1; j < stop; j++) {
			if (f[j] == 2) {
//				cout << i << " " << j << "\n";
				ans++;
			}
//			cout << f[j] << " ";
		}
		
//		cout << "-------------------------\n";
	}
	cout << ans << endl;
}

bool checkA() {
	ll k = a[2] - a[1];
	for (int i = 3; i <= n; i++)
		if (a[i] - a[i - 1] != k)
			return 0;
	return 1;
}

void solve2() {
	ll k = a[2] - a[1];
	ll p = d / k;
	
	if (p == 0) { cout << 0 << "\n"; return ; }
	
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll need = 2 * p + 1 - 2;
		
		if (need <= p) break;
		if (i + need <= n) ans++;
	}
	cout << ans << "\n";
}

void solve(int C) {
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	if ((C >= 1 && C <= 10) || n <= 5e3) solve1();
	else if ((C >= 11 && C <= 12) || checkA()) solve2();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int C, T; cin >> C >> T;
	while (T--) solve(C);
	
	return 0;
}

/*
1 ~ 10 部分分随便 DP 一下就做完了，40 分到手 

特殊性质 A 也是随便判断一下就行了 

#define int long long

*/
