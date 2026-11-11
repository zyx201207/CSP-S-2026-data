#include<bits/stdc++.h>
using namespace std;
int a[2000001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t)
	{
		t--;
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		if((a[2]-a[1])*2<=d)
		{
			printf("%d",n-1);
		}
		else
		{
			printf("%d",0);
		}
	}
	return 0;
}
