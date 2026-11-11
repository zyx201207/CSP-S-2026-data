#include<bits/stdc++.h>
using namespace std;
long long n123,n,m,a[2000010],s[2000010],da=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&n123,&n123);
	for(int i=0;i<n123;i++){
		scanf("%lld %lld",&n,&m);
		da=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i+2<=n;i++){
			da=da+i;
		}
		printf("%lld\n",da);
	}
	fclose(stdin);
	fclose(stdout);
}
