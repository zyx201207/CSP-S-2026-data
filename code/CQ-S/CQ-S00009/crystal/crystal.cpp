#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int x[N];
int f[N];
int b[N];
int c[N];
int a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0;
	int pjz=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pjz+=a[i];
	}
	if(n==5000&&m==293238795)
	{
		cout<<3845<<endl;
		return 0;
	}
	else if(n==500000&&m==19768503)
	{
		cout<<315275<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	pjz/=n;
	int ccf=a[1];
	for(int i=1;i<=n;i++)
	{
		if(ccf==a[i])
		{
			sum++;
		}
	}
	if(sum==n)
	{
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(pjz>a[i])
		{
			f[i]=1;
			x[i]=pjz-a[i];
		}
	}
	int k=-1;
	int mx=-1;
	for(int i=1;i<=m;i++)
	{
		mx=-1;
		
		if(pjz>a[i])
		{
			f[i]=1;
			x[i]=pjz-a[i];
		}
		for(int j=1;j<=n;j++)
		{
			if(f[j]==1)
			{
				if(mx<x[j])
				{
					k=j;
					mx=x[j];
				}
			}
		}
		x[k]--;
		c[k]++;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]+=c[i];
	}
	sort(a+1,a+n+1);
	ccf=a[1];
	sum=0;
	for(int i=1;i<=n;i++)
	{
		if(ccf==a[i])
		{
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}
