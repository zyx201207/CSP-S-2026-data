#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m, a[N], c[40];

bool calc(int x){
	int cnt = 0;
	for (int i = 1, j = 0; j <= 30; j++, i *= 2)
		if (x & i)
			c[++cnt] = i;
	int sum = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] >= x){
			bool ok = true;
			for (int j = 1; j <= cnt && ok; j++)
				if (!(a[i] & c[j]))
					ok = false;
			sum += ok;
			if (sum >= m)
				return true;
		}
	return false;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int L = 0, R = 1 << 30;
	while (L + 1 < R){
		int M = (L + R) / 2;
		if (calc(M))
			L = M;
		else
			R = M;
	}
	printf("%d\n", L);
	return 0;
}