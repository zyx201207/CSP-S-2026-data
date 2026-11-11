#include <bits/stdc++.h>
#define int long long
#define FOR(i,l,r) for(int i = l;i <= r;i++)
using namespace std;

int last[500005];

int cnt[300005];
int vis[300005];

stack <int> stk;

int b[500005];

int a[500005];

int n,m;

void Solve1() {
	FOR(i, 1, n) {
		while(!stk.empty()) stk.pop();
		FOR(i, 1, m) vis[i] = 0;
		FOR(j, i, n) {
			if (vis[a[j]]) {
				while(!stk.empty() && stk.top() != a[j]) {
					vis[stk.top()] = 0;
					stk.pop();
				}
			}
			else {
				vis[a[j]] = 1;
				stk.push(a[j]);
			}
		}
		FOR(i, 1, m) cnt[i] += vis[i];
	}
}

void Solve2() {
	FOR(i, 1, n) {
		last[i] = vis[a[i]];
		vis[a[i]] = i;
		b[i] = 1;
	}
	
	FOR(i, 1, n) {
		if (last[i]) {
			int t = 0;
			FOR(j, 1, last[i]) t += b[j];
			t = max(0ll, t);
			t = min(t, last[i]);
			b[last[i]] -= t;
			b[i] += t;
		}
//		FOR(j, 1, n) cout << b[j] << ' ';
//		cout << '\n';
	}
	
	FOR(i, 1, n) b[i] = b[i] + b[i-1];
	
	FOR(i, 1, n) cnt[a[i]] += max(0ll, b[i]);
}

bool check() {
	FOR(i, 1, n) if (a[i] < a[i - 1]) return 0;
	return 1;
}

void SolveA() {
	FOR(i, 1, n) last[a[i]] = i;
	FOR(i, 1, m) cnt[i] = last[i];
}

#undef int
int main () {
#define int long long

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	FOR(i, 1, n) cin >> a[i];
	
	if (check()) SolveA();
	else if (m == 2) Solve2();
	else Solve1();
	
	FOR(i, 1, m) cout << cnt[i] << ' ';
	
	return 0;
}
