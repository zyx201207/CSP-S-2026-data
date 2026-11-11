#include <bits/stdc++.h>
#define ll long long

#include <cstring>

using namespace std;

const int MAXN = 200005;
int n, m;
int a[MAXN][35], b[35], c[35];
int ans = 0;

void turnbit(int y) {
	int len = 0;
	while (y) {
		c[++len] = (y & 1);
		y >>= 1;
	}
	for (; len + 1 <= 30; ) { //当前要填充第len + 1位
		c[++len] = 0;
	}
}

bool cmppre(int wei, int id) { //to compare a[id] with b
	for (int i = 30; i >= wei; --i) {
		if (a[id][i] == 0 && b[i] == 1)
			return false;
	}
	return true;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int x = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		turnbit(x);
		memcpy(a[i], c, sizeof(c));
	}
	int cnt;
	for (int i = 30; i; --i) {
		ans += (1LL << (i - 1));
		turnbit(ans);
		memcpy(b, c, sizeof(c));
		
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (cmppre(i, j))
				++cnt;
		}
		if (cnt < m)
			ans -= (1LL << (i - 1));
	}
	printf("%d\n", ans);
	return 0;
}
