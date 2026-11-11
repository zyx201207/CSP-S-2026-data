#include<bits/stdc++.h>
using namespace std;
long long n, m, a[1010101], vis[1010101], cnt[1010101];
stack<long long>st;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= m; j++) vis[j] = 0;
		for (long long j = i; j <= n; j++) {
			long long p = a[j];
			if (vis[a[j]] == 0) {
				vis[a[j]] = 1;
				st.push(p);
			}
			else {
				while (st.size()) {
					if (st.top() == p) break;
					vis[st.top()] = 0;
					st.pop();
				}
			}
		}
		while (st.size()) {
			cnt[st.top()]++;
			st.pop();
		}
	}
	for (long long i = 1; i <= m; i++) cout << cnt[i] << ' ';
} 
