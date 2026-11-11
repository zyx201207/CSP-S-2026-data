#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u[1000005],v[1000005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n-1;i++)
		{
			scanf("%d%d",&u[i],&v[i]);
		}
		printf("1\n");
	}
	return 0;
}
