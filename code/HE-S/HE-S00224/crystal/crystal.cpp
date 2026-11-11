#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long x=0,q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[500005]={0};
	scanf("%lld %lld",&n,&m);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<i;j++)
		{
			x=x+a[j];
		}
		
		m=m-x;
		if(m==0)
		{
			q=i;
			break;
		}
	}
	printf("%d",a[q]-1);
	return 0;
}
