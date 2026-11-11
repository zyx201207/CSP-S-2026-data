#include<bits/stdc++.h> 
using namespace std;
int x[500500],ans[300500],d[300500];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[x[i]]<i&&d[x[i]]==0)
		{
			ans[x[i]]+=i;
		} 
		else
		{
			ans[x[i]]=i;
		}
		if(d[x[i]]>0)
		{
			for(int j=i-1;j>=d[x[i]]+1;j--)
			{
				if(ans[x[j]]>=j)
				{
					ans[x[j]]-=d[x[i]];
				}
				if(d[x[j]]==j)
				{
					d[x[j]]=0;
				}
			}
		}
		d[x[i]]=i;
		printf("%d ",ans[x[i]]);
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);		
	}
	return 0;
}

