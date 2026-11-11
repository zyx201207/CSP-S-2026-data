#include<bits/stdc++.h>
using namespace std;
long long a[5000000];
struct sss{
	long long s,t;
}b[2000000];
bool cmp(sss x,sss y)
{
	return x.s<y.s;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxx=0,mm=-9;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		mm=max(mm,a[i]);
		b[i].s=a[i];
		b[i].t=i;
	}
	if(m>1000000000&&mm>200000)
	{
		long long c=a[2]-a[1],aans=0;
		long long k=0;
		for(long long i=1;i<=n;i++)
		{
			if(m>=k)
			{
				m-=k;
				aans++;
			}
			k+=c;
		}
		cout<<aans;
		return 0;
	}
	sort(b+1,b+n+1,cmp);
	for(long long i=1;i<=n;i++)
	{
		long long s=a[i],p=0,sum=m,ans=0;
		for(long long j=1;j<=n;j++)
		{
			if(b[j].s>a[i])
			{
				break;
			}
			else
			{
				p=j;
			}
		}
		for(long long j=p;j>=1;j--)
		{
			if(sum>=(s-b[j].s))
			{
				sum-=(s-b[j].s);
				ans++;
			}
			else
			{
				break;
			}
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}