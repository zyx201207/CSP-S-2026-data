#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 500005, MAXM = 300005;
int n, m, a[MAXN];
set<int> idx[MAXM];
set<int> s;
vector<pair<int, int> > ans[MAXM];
int lf = 0, rt = 0, cnt = 0;
struct node {
	int x, l, r;
	bool operator < (const node & A) const {
		return l < A.l;
	}
}opt[MAXN];

void add(int x, int l, int r) {
	if (ans[x].empty())
		ans[x].push_back(make_pair(l, r));
	else if (ans[x].back().second < l - 1)
		ans[x].push_back(make_pair(l, r));
	else
		ans[x].back().second = max(ans[x].back().second, r);
}

int funC(int x, pair<int, int> y) {
	return x + y.second - y.first + 1;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		idx[a[i]].insert(i);
	}
	for (int i = n; i; --i) {
		rt = i;
		if (s.empty())
			lf = 1;
		else
			lf = min(*prev(s.end()) + 1, i);
		opt[++cnt] = {a[i], lf, rt};
		auto it = idx[a[i]].lower_bound(i);
		if (it != idx[a[i]].begin())
			s.insert(*prev(it));
	}
	sort(opt + 1, opt + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		add(opt[i].x, opt[i].l, opt[i].r);
	}
	for (int i = 1; i <= m; i++) {
		printf("%d ", accumulate(ans[i].begin(), ans[i].end(), 0, funC));
	}
	printf("\n");
	return 0;
}

//10 3 
//3 1 2 1 3 2 3 1 2 1

