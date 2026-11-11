#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[501000], c[301000], t[501000], ans[501000], v[301000], w[501000], d[501000];
int b[301000], f[501000];
int s[501000], top = 0;
set<int> st;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int num = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i - 1])
			d[++num] = a[i];
	}
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= num; i++)
		a[i] = d[i];
	n = num;
	if (m == 1) {
		printf("%d\n", n);
		return 0;
	}
	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {
			top = 0;
			for (int j = i; j <= n; j++) {
				if (st.find(a[j]) == st.end()) {
					st.insert(a[j]);
					s[++top] = a[j];
				} else {
					while (s[top] != a[j]) {
						st.erase(s[top]);
						top--;
					}
				}
			}
			for (int i = 1; i <= top; i++) 
				ans[s[i]]++, st.erase(s[i]);
		}
		for (int i = 1; i <= m; i++) {
			printf("%d ", ans[i]);
		}
		return 0;
	}
	bool flag = true;
	for (int i = 1; i <= n && flag; i++)
		if (a[i - 1] > a[i])
			flag = false;
	for (int i = n; i; i--) {
		if (b[a[i]])
			f[i] = b[a[i]];
		if (!b[a[i]])
			b[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (f[i - 1] > f[i])
			w[i] = w[i - 1], f[i] = f[i - 1];
		else
			w[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (f[i - 1] > i)
			t[i] = w[i - 1];
	}
	memset(c, 127, sizeof(c));
	for (int i = 1; i <= n; i++) {
		c[a[i]] = min(c[a[i]], t[i] + 1);
	}
	for (int i = 1; i <= n; i++)
		v[a[i]] = max(v[a[i]], i);
	if (flag) {
		for (int i = 1; i <= m; i++) {
			printf("%d\n", v[i]);
		}
		return 0;
	} 
	int inf = 2e9;
	for (int i = 1; i <= m; i++) {
		ans[i] = v[i] - c[i] + 1;
		if (c[i] > inf)
			ans[i] = 0;
		printf("%d ", ans[i]);
	}
	return 0;
}
