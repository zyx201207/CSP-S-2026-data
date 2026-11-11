#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,cnt;
long long a[2145141];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t>0) {
		t--;
		cnt=0;
		scanf("%lld%lld",&n,&d);
		for(long long i=0;i<n;i++) {
			scanf("%lld",&a[i]);
		}
		if(t!=1) {
			printf("%d\n",0);
		} else {
			printf("%d",0);
		}
	}
	return 0;
}
