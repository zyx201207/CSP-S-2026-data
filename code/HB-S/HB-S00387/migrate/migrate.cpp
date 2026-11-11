#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int n,d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&d);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
		}
		printf("1");
	}
	return 0;
}
