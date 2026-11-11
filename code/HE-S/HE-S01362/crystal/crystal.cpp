#include<bits/stdc++.h>
using namespace std;
long long n;
bool p[500001],q;
long long m,a[500001],b[500001],ans,x=1,y,j;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	b[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
		if(b[i]==0&&!p[i]&&!p[i-1])
		{
			p[i]=1;
			j=i;
		}
		ans+=x*b[i];
		if(ans>m)
		{
			y=max(x,y);
			ans=0;
			x=1;
			if(j!=0)
				i=j;
		}
		else
		{
			q=1;
			x++;
		}
	}
	if(ans>m)
	{
		x--;
		y=max(x,y);
	}
	else
	{
		if(q)
			y=max(x,y);
		else
			y=0;
	}
	printf("%lld\n",y);
}
