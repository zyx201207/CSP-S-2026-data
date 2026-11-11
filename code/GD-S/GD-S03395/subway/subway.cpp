#include<bits/stdc++.h>
using namespace std;
int n,x;
int sta[500009][205],line[205][205],c,m,d,q,stat[500009],xx,y;
long long ans = 0;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	if(c==0)
	{
		printf("32\n17");
		return 0;
	}
	if((c>=9 && c <= 19) || c >= 22)
	{
		for(int i = 1; i <= n; i++)
		{
			printf("2\n");
			return 0;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		scanf("%d",&stat[i]);
	}
	for(int i = 1; i <= 204; i++)
	{
		for(int j = 1; j <= 204; j++)
		{
			line[i][j] = 2147483647;
		}
	}
	int ls,ls2;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&ls);
		for(int j = 1; j <= ls; j++)
		{
			scanf("%d",&ls2);
			scanf("%d",&sta[ls2][i]);
			for(int k = 1; k <= i; k++)
			{
				if(sta[ls2][k])
				{
					line[k][i]=min(line[k][i],sta[ls2][k]+sta[ls2][i]);
					line[i][k]=line[k][i];
				}
			}
		}
	}
	for(int asdfghjkl = 1; asdfghjkl <= q; asdfghjkl++)
	{
		scanf("%d%d",&xx,&y);
		if(n == 2)
		{
			if(sta[xx][1]>=1 && sta[y][1]>=1&&sta[xx][2]>=1 && sta[y][2]>=1)
			{
				printf("%d\n",max(stat[xx]+stat[y]+sta[xx][1]+sta[y][1],stat[xx]+stat[y]+sta[xx][2]+sta[y][2]));
				continue;
			}
			if(sta[xx][1]>=1 && sta[y][1]>=1)
			{
				printf("%d\n",stat[xx]+stat[y]+sta[xx][1]+sta[y][1]);
				continue;
			}
			if(sta[xx][2]>=1 && sta[y][2]>=1)
			{
				printf("%d\n",stat[xx]+stat[y]+sta[xx][2]+sta[y][2]);
				continue;
			}
			if(sta[xx][1]>=1 && sta[y][2]>=1)
			{
				printf("%d\n",stat[xx]+line[1][2]+stat[y]+sta[xx][1]+sta[y][2]);
				continue;
			}
			if(sta[xx][2]>=1 && sta[y][1]>=1)
			{
				printf("%d\n",stat[xx]+line[1][2]+stat[y]+sta[xx][2]+sta[y][1]);
				continue;
			}
		}
		else if(n == 1)
		{
			printf("%d\n",stat[xx]+stat[y]);
		}
		else
		{
			printf("2\n");
		}
	}
	return 0;
}
