#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;
int n,m,put[MAXN],game[MAXN],tong[MAXN],t[MAXN];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&put[i]);
	for(int i=1;i<=n;i++)
	{
		int len=0;
		memset(tong,0,sizeof(tong));
		memset(game,0,sizeof(game));
		for(int j=1;j<=n;j++)
		{
			if(j<=i-1)continue;
			if(tong[put[j]]==0)
			{
				len++;
				game[len]=put[j];
				tong[put[j]]++;
			}
			
			if(tong[put[j]]!=0)
			{
				tong[put[j]]=1;
				bool flag=false;
				int len1=len;
				for(int k=1;k<=len1;k++)
				{
					if(game[k]==put[j])
					{
						flag=true;
						continue;
					}
					if(flag)
					{
						len--;
						game[k]=0;
					}
					
				}	
			}
			if(j==n)
			{
				if(game[len]!=put[n])
				{
					len++;
					game[len]=put[n];
				}
			}
		}
		for(int j=1;j<=len;j++)
			t[game[j]]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",t[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
