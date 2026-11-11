#include <bits/stdc++.h>
using namespace std;

int c,t,n;
long long island[2000001],d;

int dfs(int a,int b,int deep) {
	if (a==b) return 1;
	if (deep > 2) return 0;
	int res = 0;
	for (int i=a;i<n&&island[i]<=island[a]+d;i++) {
		res += dfs(i,b,deep+1);
	}
	return res
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t--) {
		scanf("%d%lld",&n,&d);
		for (int i=0;i<n;i++) {
			scanf("%lld",island+i);
		}
		printf("%d\n",dfs(0,n-1,0));
	}
	
	return 0;
}
/*

*/
