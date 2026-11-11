#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long x[200002];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int j=0;j<t;j++){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		printf("%d\n",(n-1)/2);
	}
	return 0;
}
