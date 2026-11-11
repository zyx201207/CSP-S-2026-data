#include <bits/stdc++.h>

#define END exit(0);
#define int long long

using namespace std;
using LL = long long;

const int MAXN = 2e5 + 10;

int n; LL a[MAXN], len, st[MAXN], ans;
char c[MAXN];
vector<int> L[30], R[30];
vector<LL> sum[30];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < 26; ++i) {
		L[i].push_back(0LL);
		R[i].push_back(0LL);
		sum[i].push_back(0LL);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
		st[i] = len + 1LL;
		L[c[i] - 'a'].push_back(st[i]);
		R[c[i] - 'a'].push_back(st[i] + a[i] - 1LL);
		LL lst = sum[c[i] - 'a'].back();
		sum[c[i] - 'a'].push_back(lst + a[i]);
		len += a[i];
	} 
	LL maxv = (len + 1) / 2LL;
	for (int i = len, p = n; i > maxv; ) {
		int l = max(maxv + 1LL, st[p]), r = i;
		int k = len - r + 1LL, t = len - l + 1LL;
		if (k > t)
			swap(k, t);
		int idx = c[p] - 'a'; 
		int lst = upper_bound(L[idx].begin(), L[idx].end(), t) - L[idx].begin() - 1; 
		int fst = lower_bound(L[idx].begin(), L[idx].end(), k) - L[idx].begin(); 
		if (lst <= 0) {
			ans += (r - l + 1); i = l - 1; --p;
			continue;
		} 
		else if (R[idx][lst] < k) {
			ans += (r - l + 1); i = l - 1; --p;
			continue;
		} 
		LL more = max(0LL, R[idx][lst] - t); LL pre = sum[idx][max(0LL, fst - 1LL)]; 
		ans += ((r - l + 1) - sum[idx][lst] + more + pre);
		i = l - 1;
		--p;
	}
	LL g = 0;  int cnt = 0;
	if (len % 2) maxv = len / 2;
	else maxv++;
	for (int i = 1, p = 1; i < maxv; ) {
		int l = st[p], r = min(maxv - 1, st[p] + a[p] - 1);
		int k = len - r + 1, t = len - l + 1;
		if (k > t)
			swap(k, t); 
		int idx = c[p] - 'a'; 
		int lst = upper_bound(L[idx].begin(), L[idx].end(), t) - L[idx].begin() - 1; 
		int fst = lower_bound(L[idx].begin(), L[idx].end(), k) - L[idx].begin();
		if (lst <= 0) {
			g += (r - l + 1); i = r + 1; ++p;
			continue;
		} 
		else if (R[idx][lst] < k) {
			g += (r - l + 1); i = r + 1; ++p;
			continue;
		}  
		LL more = max(0LL, R[idx][lst] - t); LL pre = sum[idx][max(0LL, fst - 1LL)];  
		g += ((r - l + 1) - sum[idx][lst] + more + pre);
		i = r + 1;
		++p;
	}
	cout << min(g, ans);
	return 0;
}