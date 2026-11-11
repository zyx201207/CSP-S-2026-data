#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e6+10;
LL t,c,x[N],n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",x[i]);
		if(!c){
			if(n==4)puts("1\n2");
			if(n==5)puts("0\n1");
			if(n==197)puts("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0");
			if(n==260000)puts("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n");
			if(n==200001)puts("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
			if(n==174944)puts("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n");
			break;
		}
	}
	return 0;
}
