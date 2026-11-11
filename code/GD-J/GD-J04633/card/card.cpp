//card
#include <stdio.h>
int n, m, a[514514], vQueue[514514], vQEnd = 1, FirstAppear[314514];
long long Results[314514];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d %d", &n, &m);
	int i, j, isSpecialA = 1;
	for(i = 1; i <= n; i += 1) {
		scanf("%d", &a[i]);
		if(i > 1 && a[i] < a[i - 1]) {
			isSpecialA = 0;
		}
	}
	if(m <= 2) {
		Results[a[n]] = n;
		for(i = 1; i < n; i += 1) {
			if(a[i] != a[n]) Results[a[n] % 2 + 1] += 1;
		}
	}
	else if(isSpecialA == 1) {
		for(i = 1; i <= n; i += 1) {
			Results[a[i]] = i;
		}
	}
	else {
		for(i = 1; i <= n; i += 1) {
			vQEnd = 1;
			for(j = i; j <= n; j += 1) {
				if(FirstAppear[a[j]] < vQEnd && vQueue[FirstAppear[a[j]]] == a[j]) {
					vQEnd = FirstAppear[a[j]];
				}
				vQueue[vQEnd] = a[j];
				FirstAppear[a[j]] = vQEnd;
				vQEnd += 1;
			}
			for(j = 1; j <= m; j += 1) {
				if(FirstAppear[j] < vQEnd && vQueue[FirstAppear[j]] == j) {
					Results[j] += 1;
				}
			}
		}
	}
	for(i = 1; i <= m; i += 1) printf("%lld ", Results[i]);
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
