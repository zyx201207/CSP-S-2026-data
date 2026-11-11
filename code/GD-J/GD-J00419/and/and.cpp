#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, m, a[N], B[35], ans;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	for(int i=1; i<=m; i++)
		for(int j=30; j>=0; j--)
			if(a[i]>>j&1) B[j]++;
	for(int i=2; i+m-1<=n; i++) {
		int now = 0;
		for(int j=30; j>=0; j--)
			if(a[i-1]>>j&1) B[j]--;
		for(int j=30; j>=0; j--)
			if(a[i+m-1]>>j&1) B[j]++;
		for(int j=30; j>=0; j--)
			if(B[j]==m) now += (1<<j);
		ans = max(ans, now);
	} printf("%d", ans);
	return 0;
} 
