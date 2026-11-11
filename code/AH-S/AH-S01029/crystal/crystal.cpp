#include<bits/stdc++.h>
using namespace std;
long long c[500010],d[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	if(a<=5000&&b<=1000000)
	{
		for(long long i=1;i<=a;i++)
		{
			cin>>c[i];
		}
		sort(c+1,c+a+1);
		long long ans=0;
		for(long long i=c[1];i<=c[a];i++)
		{
			long long cha=0,jie=0,he=0;
			for(long long j=1;j<=a;j++)
			{
				if(c[j]>i)
				{
					break;
				}
				jie++;
				d[jie]=i-c[j];
			}
			sort(d+1,d+jie+1);
			for(long long j=1;j<=jie;j++)
			{
				cha+=d[j];
				if(cha>b)
				{
					break;
				}
				he++;
			}
			if(he>ans)
			{
				ans=he;
			}
		}
		cout<<ans;
		return 0;
	}
	long long qizi=1,boo,bo=1;
	for(long long i=1;i<=a;i++)
	{
		cin>>c[i];
		if(c[i]!=i)
		{
			qizi=0;
		}
		if(i==2)
		{
			boo=c[2]-c[1];
		}
		if(i>2&&c[i]-c[i-1]!=boo)
		{
			bo=0;
		}
	}
	if(qizi==1)
	{
		long long acans=1;
		for(long long i=1;i<=a;i++)
		{
			long long pingfang=(i*(i+1))/2;
			if(pingfang>b)
			{
				break;
			}
			acans++;
		}
		if(acans>a)
		{
			cout<<a;
		}
		else
		{
			cout<<acans;
		}
		return 0;
	}
	else if(bo==1&&boo!=0)
	{
		b/=boo;
		long long pacans=1;
		for(long long i=1;i<=a;i++)
		{
			long long ercifang=(i*(i+1))/2;
			if(ercifang>b)
			{
				break;
			}
			pacans++;
		}
		if(pacans>a)
		{
			cout<<a;
		}
		else
		{
			cout<<pacans;
		}
		return 0;
	}
	else if(bo==1&&boo==0)
	{
		cout<<a;
		return 0;
	}
	else
	{
		cout<<1;
		return 0;
	}
}
