#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10; 

int n,m;
int a[N];

int cmp(int a,int b)
{
	return a>b;
}

bool flag;
bool en;

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=i)
		{
			en=true;
		}
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		printf("%lld\n",a[1]);
		return 0;
	}
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		printf("%lld\n",ans);
		return 0;
	}
	if(m==2)
	{
		int mx=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					mx=max(mx,a[i] & a[j]);
					//printf("%d\n",a[i] & a[j]);
				}
			}
		}
		printf("%lld",mx);
		return 0;
	}
	int p=a[1];
	for(int i=2;i<=m;i++)
	{
		p=p&a[i];
	}
	printf("%lld\n",p);
}
