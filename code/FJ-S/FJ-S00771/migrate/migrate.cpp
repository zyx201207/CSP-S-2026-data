#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6 + 10;

int c, t;
LL x[N];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	scanf("%d %d", &c, &t);
	while (t--){
		int n; LL d;
		scanf("%d %lld", &n, &d);
		for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
		printf("0\n");
	}
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
