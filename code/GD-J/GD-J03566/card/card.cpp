#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, M = 3e5 + 5;

int sum[M] = { };
int a[N] = { }, h[M] = { };
int nxt[M] = { };
int n, m;

void pls(int rnd);

int main() {
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		scanf("%i", &a[i]);
	for (int i = 1; i <= n; i++) 
		pls(i);
	for (int i = 1; i <= m; i++) 
		printf("%i ", sum[i]);
	return 0;
} 

void pls(int rnd) {
	fill(h, h + M, 0);
	fill(nxt, nxt + M, 0);
	int p = 0;
	for (int i = rnd; i <= n; i++) {
		if (h[a[i]]) {
			p = h[a[i]] - 1;
			for (int j = h[a[i]]; j < i; j++) 
				h[a[i]] = 0; 
			h[a[i]] = i;
		}
		else 
			h[a[i]] = i;
		nxt[p++] = i;
	}
	for (int i = 0; i < p; i++) 
		sum[a[nxt[i]]]++;
}
//10 3 3 1 2 1 3 2 3 1 2 1 
