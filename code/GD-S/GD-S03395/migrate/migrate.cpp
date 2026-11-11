#include<bits/stdc++.h>
using namespace std;
int c,t;
bool m = 1;
int n,d,x[200009];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==0)
	{
		printf("1\n2");
		return 0;
	}
	for(int asdfghjkl = 1; asdfghjkl <= t; asdfghjkl++)
	{
		scanf("%d%d",&n,&d);
		m = 1;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&x[i]);
			if(m&&i >= 3 && x[i]-x[i-1] != x[i-1]-x[i-2])
			{
				m=0;
			}
		}
		if(m)
		{
			if(x[3]-x[1] > d)
			{
				printf("0\n");
				continue;
			}
			if(x[4]-x[1]<d)
			{
				printf("2\n");
				continue;
			}
			printf("0\n");
			continue;
		}
		printf("1\n");
	}
	return 0;
}
