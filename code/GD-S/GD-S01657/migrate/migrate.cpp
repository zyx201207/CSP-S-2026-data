#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
const int N = 2e6 + 5;

bool memst;

ll subid;

ll n, d;

vector<ll> a;
int tol[N], tor[N], cnt[2][N];
int tmp[N];

ll calc() {
	if (a.size() <= 3)
		return 0;
	for (int i = 0; i < a.size(); i++)
		tol[i] = tor[i] = cnt[0][i] = cnt[1][i] = tmp[i] = 0;
	
	tol[0] = -1;
	tol[1] = 0;
	for (int i = 2; i < a.size(); i++) {
		tol[i] = tol[i - 1];
		while (a[i] - a[tol[i]] > d)
			tol[i]++;
	}
	tor[a.size() - 1] = a.size();
	tor[a.size() - 2] = a.size() - 1;
	for (int i = a.size() - 3; i >= 0; i--) {
		tor[i] = tor[i + 1];
		while (a[tor[i]] - a[i] > d)
			tor[i]--;
	}
	
	for (int i = 0; i < a.size(); i++) {
		int now = tor[i];
		if (now == a.size())
			continue;
		if (now - 1 != i)
			cnt[0][now - 1]++;
		
		if (tor[i] != a.size()) {
			if (tol[tor[i] - 1] == i)
				cnt[0][tor[i] - 1] += tmp[i];
			if (tol[tor[i]] == i)
				tmp[tor[i]] += tmp[i];
		}
		
		tmp[now]++;
	}
	
	for (int i = 0; i < a.size(); i++)
		tmp[i] = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		int now = tol[i];
		if (now == -1)
			continue;
		if (now != i - 1)
			cnt[1][now]++;
		
		if (tol[now] != -1) {
			if (tor[tol[i] + 1] == i) 
				cnt[1][tol[i]] += tmp[i];
			if (tor[tol[i]] == i)
				tmp[tol[i]] += tmp[i];
		}
		
		tmp[now]++;
	}
	ll ret = 0;
	for (int i = 1; i < a.size() - 2; i++) {
		ret += 1ll * cnt[0][i] * cnt[1][i];
//		if (cnt[0][i] > 0 && cnt[1][i] > 0)
//		cerr << "? " << i << ":" << cnt[0][i] << ' ' << cnt[1][i] << '\n';
	}
	return ret;
}

void slv() {
	cin >> n >> d;
	ll ans = 0;
	for (ll i = 1, x; i <= n; i++) {
		cin >> x;
		if (a.size() > 0 && x - a.back() > d) {
			ans += calc();
			vector<ll>().swap(a);
		}
		a.pb(x);
	}
	if (a.size()) {
		ans += calc();
		vector<ll>().swap(a);
	}
	cout << ans << '\n';
}

bool memed;

int main() {
//	freopen("1.in", "r", stdin);
//	freopen("migrate6.in", "r", stdin);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> subid;
	int T = 1;
	cin >> T;
//	T = 1;
	while (T--)
		slv();
//	cerr << "time use: " << 1. *(clock()) / CLOCKS_PER_SEC << '\n';
//	cerr << "memory use: " << (int)(&memed - &memst) / 1048576 << '\n'; 
	return 0;
}
