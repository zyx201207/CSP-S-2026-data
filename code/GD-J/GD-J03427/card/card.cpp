#include <bits/stdc++.h>
using namespace std;

int n, m, a[500010];
long long js[300010];

int main (){
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf ("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++){
		int s[300010], p[500010];
		for (int j = i; j <= n; j++){
			if (s[a[j]])
				for (int k = p[a[j]]; k <= j; k++)
					s[a[k]]--;
			s[a[j]]++;
			p[a[j]] == j;
		}
		for (int j = 1; j <= m; j++)
			js[j] += s[j];
	}
	for (int i = 1; i <= m; i++)
		printf ("%lld ", js[i]);
	return 0;
}
