/*
期望得分：52pts 
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 5e5 + 7;

int n, m, a[N];

namespace brute {
	int stk[N], top;
	int ins[N], pos[N], pre[N];
	int ans[N];
	void calc(int s) {
		fill(ins + 1, ins + m + 1, 0);
		fill(pos + 1, pos + m + 1, 0);
		fill(stk + 1, stk + top + 1, 0);
		fill(pre + 1, pre + m + 1, 0);
		top = 0;
		auto count = [&](int x) -> int {
			if (!top) return 0;
			return *lower_bound(pos + 1, pos + top + 1, x) == x;
		};
 		for (int i = s; i <= n; i++) {
// 			printf("pos : %d, ins : %d\n", ins[a[i]], count(ins[a[i]]));
			if (ins[a[i]] && count(pre[a[i]])) top = ins[a[i]] - 1, ins[a[i]] = 0;
			stk[++top] = a[i];
			pos[top] = i;
			pre[a[i]] = i;
			ins[a[i]] = top;
//			printf("i : %d, a[i] : %d,  top : %d\n", i, a[i], top);
//			for (int j = 1; j <= top; j++) printf("%d ", pos[j]);
//			puts("");
		}
		for (int i = 1; i <= top; i++) ++ans[stk[i]];
//		for (int i = 1; i <= top; i++) printf("%d ", stk[i]);
//		puts("");
	}
	void solve() {
//		calc(1);
		for (int i = 1; i <= n; i++) calc(i); 
		for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
		puts("");
	}
}

namespace testA {
	bool check() {
		for (int i = 1; i < n; i++) if (a[i] > a[i + 1]) return false;
		return true;
	}
	void solve() {
		map<int, int> mp;
		for (int i = 1; i <= n; i++) ++mp[a[i]];
		ll sum = 0;
		for (auto x : mp) {
			sum += x.second;
			printf("%lld ", sum);
		}
		puts("");
	}
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if ((ll)n * n <= 100000000) brute::solve();
	else if (testA::check()) testA::solve();
	else {
		while (1);
	}
	return 0;
}

