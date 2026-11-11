#include <bits/stdc++.h>
#define int long long 
#define FOR(i,l,r) for(int i = l;i <= r;i++)
using namespace std;

//bool AA;

int st[600005][55];
int lg[600006];

int pre[600005];
int a[600005];

int ans;
int n,m;

int query(int l, int r) {
	int len = r - l + 1;
	return max(st[l][lg[len]], st[r-(1<<lg[len])+1][lg[len]]);
}

bool check(int mid) {
	
	FOR(i, 1, n-mid) {
		int sum = pre[i+mid-1] - pre[i - 1];
		int goal = query(i,i+mid-1) * mid;
		if (goal >= sum && goal - sum <= m) {
//			cout << goal << ' ' << sum << ' ' << i << "\n\n";
			return 1;
		}
	}
	return 0;
	
}

#undef int
int main () {
#define int long long

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	FOR(i, 2, 600000) lg[i] = lg[i>>1] + 1;
	
	cin >> n >> m;
	
	FOR(i, 1, n) cin >> a[i];
	
//	cout << "<scanf> Pass .\n";
	
	sort(a + 1,a + n + 1);
	
//	cout << "<sort> Pass .\n";
	
	FOR(i, 1, n) st[i][0] = a[i];
	
	FOR(i, 1, n) pre[i] = pre[i - 1] + a[i];
	
//	cout << "<SUM init> Pass .\n";
	
	for(int i = 1;(1<<i) <= n;i++)
		for(int j = 1;j+(1<<i)-1 <= n;j++) st[j][i] = max(st[j][i-1], st[j+(1<<i-1)][i-1]);
	
//	cout << "<ST init> Pass .\n";
	
	int l = 1, r = n;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
//		cout << l << ' ' << r << ' ' << mid << '\n';
	}
	
	cout << ans << '\n';
	
//	for(int i = 0; (1<<i) <= n;i++) {
//		FOR(j, 1, n) cout << st[j][i] << ' ';
//		cout << '\n';
//	}
//	cout << '\n';
//	FOR(i, 1, n) cout << pre[i] << ' ';

//	bool BB;
	
//	cout << "[Memory] " << (&AA - &BB) / 1024 / 1024 / 1024;
	
	return 0;
} 
