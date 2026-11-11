#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 2e5 + 10;
int a[MAXN];

int main() {
	freopen("card4.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = i + 1; j <= n; i++) {
			if (a[j - 1] != a[j]) ans++;
		}
		
		printf("%d", ans + 1);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
