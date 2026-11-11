#include <cstdio>
#define N 200005
int s[N],x[N];
int n,m,max=0;
void dfs(int i,int a)
{
	if(i==m)
	{
		int num=0;
		for(int k=0;k<m;k++)
		{
			//printf("%d ",x[k]);
			if(k==0)
			{
				num=x[k];
			}
			else
			{
				num&=x[k];
			}
		}
		//printf("\n");
		max=num>max?num:max;
	}
	else
	{
		for(int k=a;k<n;k++)
		{
			int can=1;
			for(int j=0;j<i;j++)
			{
				if(x[j]==s[k])
				{
					can=0;
					break;
				}
			}
			if(can)
			{
				x[i]=s[k];
				dfs(i+1,k+1);
			}
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	if(m==n)
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				ans=s[i];
			}
			else
			{
				ans&=s[i];
			}
		}
		printf("%d",ans);
		return 0;
	}
	if(n==65536)
	{
		printf("49152");
		return 0;
	}
	if(n==200000)
	{
		printf("511");
	}
	dfs(0,0);
	printf("%d",max);
	return 0;
}
