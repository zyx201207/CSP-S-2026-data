#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++){
		scanf("%lld%lld",&n,&d);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[j]);
		}
		int z=n-d-1-(d-2);
		printf("%d\n",z);
	}
	return 0;
}
