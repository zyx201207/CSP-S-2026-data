#include <bits/stdc++.h>
using namespace std; 
long long i, j, k[505], n, m, x, y, w[2000050], t, p, q, c, d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld", &c, &t);
	while(t--){
		scanf("%lld%lld", &n, &d);
		for(i=1; i<=n; i++){
			scanf("%lld", &w[i]);
		}
		q=w[2]-w[1];
		p=d/q;
		if(p==1) printf("0\n");
		else {
			x=2*p;
			printf("%lld\n", n-x+1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}	
