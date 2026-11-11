#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int n, m, a[N], cnt[35], pow2[35];
string s[N];
int vis[N][35];
struct Node {
	int id, v;
}b[N];

bool cmp(Node x, Node y) {
	return x.v > y.v;
}

void calc() {
	pow2[0] = 1;
	for(int i = 1; i <= 30; i++) pow2[i] = pow2[i - 1] * 2;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	calc();
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		int x = a[i];
		while(x > 0) s[i] += (x % 2 + '0'), x /= 2;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < s[i].size(); j++) {
			if(s[i][j] == '1') cnt[j]++;
		}
	}
	int maxn = 0;
	for(int i = 0; i <= 31; i++) {
		if(cnt[i] >= m) maxn = i;
	}
	for(int i = 1; i <= n; i++) {
		if(s[i][maxn] == '1') vis[i][maxn] = 1;
	}
	for(int i = maxn - 1; i >= 0; i--) {
		int res = 0;
		for(int j = 1; j <= n; j++) {
			if(!vis[j][i + 1]) continue;
			if(s[j][i]) res++;
		}
		if(res < m) continue;
		for(int j = 1; j <= n; j++) {
			if(!vis[j][i + 1]) continue;
			if(s[j][i] == '1') vis[j][i] = 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		b[i].id = i;
		for(int j = 0; j <= maxn; j++) {
			if(vis[i][j]) b[i].v += pow2[j];
		}
	}
	sort(b + 1, b + n + 1, cmp);
	int ans = (1 << 30) - 1;
	for(int i = 1; i <= m; i++) {
		ans = ans & a[b[i].id];
	}
	cout << ans;
}
