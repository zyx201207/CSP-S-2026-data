#include<bits/stdc++.h>
using namespace std;

int cnt[31];

void insert(int x) {
	int c = 0;
	while(x) {
		if(x & 1) cnt[c]++;
		x >>= 1;
		c++;
	}
}

void del(int x) {
	int c = 0;
	while(x) {
		if(x & 1) cnt[c]--;
		x >>= 1;
		c++;
	}
}

int calc(int m) {
	int ans = 0;
	for(int i = 0; i <= 30; i++){
		if(cnt[i] == m) ans += (1 << i);
	}
	return ans;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.end(), greater<int>());
	
	for(int i = 1; i <= m - 1; i ++) insert(a[i]);
	int ans = 0;
	for(int i = m; i <= n; i++) {
		insert(a[i]);
//		for(int i = 0; i <= 30; i++) cout << cnt[i] << ' ';
//		cout << '\n';
		ans = max(ans, calc(m));
		del(a[i - m + 1]);
	}
	cout << ans;
	
	return 0;
}
