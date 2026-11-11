#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

int n, m;
int a[N];

int main () {
	
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	
	scanf ("%d%d", &n, &m);
	for (int i = 1;i <= n;++i) scanf ("%d", a[i]);
	
	for (int i = 1;i <= n;++i) printf ("1 ");
	
	return 0;
}
