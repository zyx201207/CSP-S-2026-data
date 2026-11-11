/*
期望得分：100pts 
*/ 
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2e5 + 7;

int n, m, a[N];

int read() {
	int x = 0; char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return x;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
//	scanf("%d%d", &n, &m);
	n = read(), m = read();
	multiset<int> st, tmp;
	for (int i = 1; i <= n; i++) {
		st.insert(read());
	}
	int ans = 0;
	for (int i = 30; i >= 0; i--) {
//		for (auto j : st) printf("%d ", j);
//		puts("");
		tmp = st;
		for (auto S : st) {
			if (!(S & (1 << i))) tmp.erase(tmp.find(S));
		}
		if ((int)tmp.size() >= m) {
			ans |= (1 << i);
			st = tmp;
		}
	}
	printf("%d\n", ans);
//	printf("%d\n", clock());
	return 0;
}
/*
4 2
4 3 1 3 
*/

