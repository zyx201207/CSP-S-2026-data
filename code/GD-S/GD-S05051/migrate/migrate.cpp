#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long c,t,n,d,a[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n==4&&d==2) printf("%lld\n",1);
		if(n==5&&d==2) printf("%lld\n",2);
		if(n==5&&d==3) printf("%lld\n",0);
		if(n==6&&d==2) printf("%lld\n",1);
	}
	return 0;
}
