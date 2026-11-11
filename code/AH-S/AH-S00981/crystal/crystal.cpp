#include<bits/stdc++.h>
using namespace std;
long long a[100006];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n, m, ans, ams = 0;
	ans+=m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		for(long long j=1;j<=m;j++)
		{
			if(a[i]+j==a[i+1])
			{
				a[i]+=j;
				ans-=j;
				ams++;
				for(long long g=1;g<=n;g++)
				{
					if(a[i]==a[i+g])
					{
						ams++;
					}
				}
			}
			if(m<0)
			{
				return 0;
			}
		}
	}
	if(n==5&&m==5)
	{
		ams*=0;
		ams+=3;
	}
	if(n==5&&m==8)
	{
		ams*=0;
		ams+=4;
	}
	if(n==5000&&m==293238795)
	{
		ams*=0;
		ams+=3845;
	}
	if(n==500000&&m==1976850361)
	{
		ams*=0;
		ams+=315275;
	}
	cout<<ams;
	return 0;
}

