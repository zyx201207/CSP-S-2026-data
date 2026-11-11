#include <bits/stdc++.h>
using namespace std;
const int N = 500011;

int n, m, a [N], g [N], q [N], t;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a [i]);
	for (int i = 1; i <= n; i++) {
		t = 0;
		for (int j = i; j <= n; j++) {
			for (int k = 1; k <= t; k++)
				if (a [q [k]] == a [j]) {
					t = k - 1;
					break;
				}
			q [++t] = j;
		}
		for (int i = 1; i <= t; i++) g [a [q [i]]]++;
	}
	for (int i = 1; i <= m; i++) printf("%d ", g [i]);
	return 0;
}
