#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,x[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		long long k=x[2]-x[1];
		if(k>(d>>1))printf("0\n");
		else
		{
			long long len=d/k+1;
			printf("%lld\n",n-len);
		}
	}
	return 0;
}
