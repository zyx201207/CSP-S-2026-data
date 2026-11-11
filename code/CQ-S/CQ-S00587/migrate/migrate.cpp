#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e6+5;
int c,T,n;
LL d;
LL a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		printf("%d\n",T);
	}
	return 0;
}
