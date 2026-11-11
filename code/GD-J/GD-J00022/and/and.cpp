#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
bool b[200005];
int is[200005][33];
long long ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	for(int j=1;j<=n;j++)
	{
		b[j]=false; 
		scanf("%lld",&a[j]);
		long long xx=a[j];
		int k=-1;
		while(xx>0)
		{
			is[j][++k]=xx%2;
			xx/=2;
		}
	}
	for(int wei=30;wei>=0;wei--)
	{
		int num=0;
		for(int i=1;i<=n;i++)
		{
			if(is[i][wei]==1&&b[i]==false)
			{
				num++;
			}
		}
		if(num>=m)
		{
			ans+=1<<wei;
			for(int i=1;i<=n;i++)
			{
				if(is[i][wei]==0)
				{
					b[i]=true;
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
