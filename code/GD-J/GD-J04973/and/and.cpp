#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,shai[200005],jie[35],ans;
long long pinfang(long long p)
{
	int k=1;
	for(int i=1;i<=p;i++)k*=2;
	return k; 
}
struct node
{
	long long x;
	long long cun[35];
}a[200005];
bool cmp(node p,node b)
{
	return p.x>b.x;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)shai[i]=1;
	for(long long i=0;i<=30;i++)jie[i]=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].x;
		for(long long j=30;j>=0;j--)
		{
			if(a[i].x>=pinfang(j))
			{
				a[i].x-=pinfang(j);
				a[i].cun[j]=1;
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=30;i>=0;i--)
	{
		int count=0;
		for(long long j=1;j<=n;j++)if(shai[j]&&a[j].cun[i]==1)count++;
		if(count>=m)
		{
			for(long long j=1;j<=n;j++)
			{
				if(a[j].cun[i]!=1)shai[j]=0;
			}
			jie[i]++;
		}
	}
	for(long long i=0;i<=30;i++)
	{
		ans+=jie[i]*pinfang(i);
	}
	cout<<ans;
	return 0;
}
