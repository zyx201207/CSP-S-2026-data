//migrate.cpp
#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;

int C,T,n;
LL a[2000005];
ULL d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%llu",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		LL t=a[2]-a[1];
		printf("%llu\n",d/t-1);
	}
	return 0;
}
