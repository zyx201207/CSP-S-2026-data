#include<bits/stdc++.h>
using namespace std;
struct er{
	long long e;
	int xun;
}a1[200001]={};
int m,n,l=0,minn=31;
long long max1=0,maxn=0,max2=0;
long long k=1;
long long a[200001];
long long mod[200001]={};
long long h=1;
long long b[200001];
long long w=1;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		while(a[i]!=0)
		{	
			a1[i].e+=(a[i]%10)*k;
			k*=10;
			a[i]/=10;
			a1[i].xun++;
		}
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				minn=min(a1[i].xun,a1[j].xun);
				max1=max(a1[i].e,a1[j].e);
				for(int z=1;z<=minn;z++)
				{
					if(a1[i].e%h==1&&a1[j].e%h==1)
					{
						max2+=1*w;
						w*=2;
					}
				}
				for(int t=0;t<n;t++)
				{
					b[t]=max2;
				}
			}
		}
		sort(b,b+n,cmp);
		cout<<b[0];
	}

	return 0;
} 
