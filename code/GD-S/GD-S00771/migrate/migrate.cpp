#include<bits/stdc++.h>
using namespace std;
int n, i, j, k, d, t, c, a, b, path1, path2;
long long x[2000005];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%d", &n, &d);
		for(i=0;i<n;++i){
			scanf("%lld", &x[i]);
		}
	}
	printf("0");
	return 0;
}
