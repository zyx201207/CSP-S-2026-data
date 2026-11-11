#include<bits/stdc++.h>
using namespace std;
long long qwe,t,n,m,a[1001],b[1001][1001][2],nm;
void ss(long long s,long long s1,long long x,long long s2,long long w)
{
	if(s>s1)
	{
		return;
	}
	if(b[s2][s][1]>w)
	{
		b[s2][s][1]=w;
		b[s2][s][0]=0;
	}
	b[s2][s][0]++;
	long long nm=0;
	for(long long i=s+1;i<=s1;i++)
	{
		nm=a[i]-a[s];
		if(nm<=x)
		{
			ss(i,s1,x,s2,w+1);
		}
		else
		{
			break;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>qwe>>t;
	for(long long i=1;i<=t;i++)
	{
		nm=0;
		memset(b,0,sizeof(b));
		cin>>n>>m;
		for(long long j=1;j<=n;j++)
		{
			for(long long k=1;k<=n;k++)
			{
				b[j][k][1]=10000000000;
			}
		}
		for(long long j=1;j<=n;j++)
		{
			long long qw;
			cin>>qw;
			a[j]=qw;
		}
		for(long long j=1;j<=n;j++)
		{
			ss(j,n,m,j,0);		
		}	
		for(long long j=1;j<=n;j++)
		{
			for(long long k=1;k<=n;k++)
			{
				if(b[j][k][0]==2)
				{
					nm++;
				}
			}
		}
		cout<<nm<<endl;
	}
	return 0;
}
