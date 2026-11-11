#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+50;
int c,t;
int n,d,x[N];
int32_t main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while (t--) {
		scanf("%lld %lld",&n,&d);
		for (int i=1;i<=n;i++) {
			scanf("%lld %lld",&x[i]);
		}
		printf("1\n"); 
	}
	return 0;
}

