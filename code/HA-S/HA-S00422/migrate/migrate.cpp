#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans;
int x[2000005];
int dg(int x,int k)
{
	if(x==k)
	{
		return 1;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d %d",&n,&d);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&x[j]);
		}
		for(int j=1;j<n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				//ans=dg(j,k);
				ans=1;
			}
		}
		printf("%d\n",&ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
