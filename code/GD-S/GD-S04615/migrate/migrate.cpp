#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000005
ll i, j, k, n, m, ok[N], a[N], des[N], qian, d, cnt;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%*d%lld", &k);
	while(k--){
		cnt=0;
		scanf("%lld%lld", &n, &d);
		for(i=1; i<=n; i++){
			scanf("%lld", &a[i]);
		}
		a[n+1]=1e18+1;
		for(i=1; i<=n-2; i++){
			for(j=i+2; j<=n; j++){
				if(a[j+1]-a[i]>d&&a[j]-a[i]<=d){
					des[i]=j;
					ok[i]=1;
					break;
				}
			}
		}
		for(i=1; i<=n-3; i++){
			if(ok[i]){
				qian=des[i]-1;
				if(ok[qian]) cnt++;
			}
		}
		printf("%lld\n", cnt);
	}
	return 0;
}
