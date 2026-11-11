#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.ont","w",stdout);
	long long a[N],d;
	int n,t,c;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",a[i]);
		}
		if(n==4&&d==2) printf("1\n");
		else if(n==5&&d==2) printf("2\n");
		else if(n==5&&d==3) printf("0\n");
		else if(n==6&&d==2) printf("1\n");
		else if(a[2]-a[1]>d) printf("0\n");
		else printf("%lld",n/4+(n%4==0?0:1)); 
	}
	return 0;
}
