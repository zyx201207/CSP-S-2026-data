#include<bits/stdc++.h>
#include<cstdio> 
using namespace std;
const long N=510000;
long n,m,c[N],k[N],num=0,p[N],right,ans[N];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long i=1;i<=n;i++)
	{
		scanf("%ld",&c[i]);
	}
	
	for(long i=1;i<=n;i++)
	{
		num=0;
		for(long j=1;j<=n;j++)
		{
			k[j]=0;p[j]=0;
		}
		for(long j=i;j<=n;j++)
		{
			num++;
			if(p[c[j]]>0)
			{
				p[c[j]]=0;
				for(long j1=num-1;j1>0;j1--)
				{
					if(k[j1]==c[j])
					{
						k[j1]==0;
					}
					
				}
				for(long j1=num-1;j1>0;j1--)
				{
					if(k[j1]!=0&&p[k[j1]]>0)
					{
						p[k[j1]]--;
						k[j1]=0;
						break;
					}
				}
				
			}
			k[num]=c[j];
			p[c[j]]++;
		}
		for(long j=1;j<=m;j++)
		{
			ans[j]+=p[j];
		}

	}
	for(long j=1;j<=m;j++)
	{
		printf("%ld ",ans[j]);
	}
	return 0;
}

