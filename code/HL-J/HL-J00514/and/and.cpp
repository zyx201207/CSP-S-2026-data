#include<bits/stdc++.h>
using namespace std;

int n, a[200010], m;

int main(){
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int ma = -1;
	for (int i = 1; i <= n - 1; i++)
		for (int j = i + 1; j <= n; j++)
			ma = max(a[i] & a[j], ma);
	printf("%d\n", ma);
	
	return 0;
}
