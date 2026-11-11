#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m;
int a[N], ans[M];

bool ok[310];
void solve1() {
	stack<int> stk;
	for(int s = 1; s <= n; s++) {
		memset(ok, 0, sizeof ok);
		for(int i = s; i <= n; i++) {
			if(ok[a[i]]) {
				while(!stk.empty()) {
					int u = stk.top();
					stk.pop();
					ok[u] = 0;
					if(u == a[i]) break;
				}
			}
			ok[a[i]] = 1;
			stk.push(a[i]);
		}
		for(int i = 1; i <= m; i++) {
			if(ok[i]) {
				ans[i]++;
//				cout << s << ' ' << i << endl;
			}
		}
		while(!stk.empty()) stk.pop();
	}
	return;
}

void solve2() {
	for(int i = 1; i <= n; i++) ans[a[i]] = i;
}

int las[M];
void solve3() {
	for(int s = 1; s <= n; s++) {
		int now = s;
		while(now <= n) {
			ans[a[now]]++;
			now = las[a[now]] + 1;
		}
//		if(now > n) ans[a[n]]++;
	}
}

int cnt[M];
void solve4() {
	queue<int> q;
	for(int i = 1; i <= m; i++) {
		int now = las[i];
		while(now <= n) {
			now = las[a[now]];
			q.push(a[now]);
			now++;
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			ans[u] += cnt[i];
		}
	}
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool oka = 1;
	int okb = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
		las[a[i]] = i;
		if(a[i] < a[i - 1]) oka = 0;
		if(a[i] != a[i - 1]) okb++;
	}
	if(n <= 500) {
		solve1();
	} else if(oka) {
		solve2();
	} else if(okb <= 5000 || n <= 1e4) solve3();
	else solve4();
	
	for(int i = 1; i <= m; i++) printf("%d ", ans[i]);
	return 0;
}
