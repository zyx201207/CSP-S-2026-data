#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m, a[N], cnt[M], ans[M]; 
queue<int> q;

signed main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) cnt[j] = 0;
		for(int j = i; j <= n; j++) {
			if(cnt[a[j]]) {
				while(q.size() && q.front() != a[j]) {
					cnt[q.front()] = 0;
					q.pop();
				}
			}else {
				q.push(a[j]);
				cnt[a[j]] = 1;
			}
		}
		while(q.size()) {
			ans[q.front()]++;
			q.pop();
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}

