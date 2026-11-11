#include<bits/stdc++.h>
using namespace std;
long long a[200005],h[200005];
bool cmp(long long &x,long long &y)
{
	return x>y;
};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(m==1)
	{
		sort(a+1,a+n+1,cmp);
		printf("%lld",a[1]);
		return 0;
	}
	int f=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			h[f]=a[i]&a[j];
			f++;
		}
	}
	if(m==2)
	{
		sort(h+1,h+n+1,cmp);
		printf("%lld",h[1]);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
