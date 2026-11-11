#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x,a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int z=1;z<=t;z++)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		x=d/(a[2]-a[1])*2;
		if(x==0||x==2)
			cout<<0<<"\n";
		else
			cout<<max((long long)0,n-x+1)<<"\n";
	}
	return 0;
}

