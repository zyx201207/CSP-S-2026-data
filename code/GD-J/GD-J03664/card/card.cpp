#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

long long n, m;
long long r;
long long a[N], ans[N];
long long cnt[N];
vector<long long> q;

void solve() {
	for(long long i = 1;i <= n;i++) cnt[a[i]]++, ans[a[i]] = n;
	for(long long i = 1;i <= n;i++) {
		cnt[a[i-1]]--;
		if(cnt[a[i-1]] == 0) {
			ans[a[i-1]] -= (n - i + 1);
		}
	}
	for(long long i = 1;i <= m;i++) cout << ans[i] << ' ';
	cout << '\n'; 
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++) cin >> a[i];
	if(n > 5000) {
		solve();
		return 0;
	}
	for(long long i = 1;i <= n;i++) {
		q.clear();
		for(long long j = i;j <= n;j++) {
			if(cnt[a[j]]) {
				cnt[a[j]]--;
				while(q[q.size() - 1] != a[j] && q.size() > 0) cnt[q[q.size() - 1]]--, q.pop_back();
				if(q.size() > 0) q.pop_back();
			}
			q.push_back(a[j]);
			cnt[a[j]]++;
		}
		for(auto v : q) ans[v]++;
		for(long long i = 1;i <= m;i++) cnt[i] = 0;
	}
	for(long long i = 1;i <= m;i++) cout << ans[i] << ' ';
	return 0;
}
