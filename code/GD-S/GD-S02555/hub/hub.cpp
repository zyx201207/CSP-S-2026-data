#include <bits/stdc++.h>
using namespace std;
int C,T,n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		for (int i=1,u,v;i<n;i++)
			scanf("%d%d",&u,&v);
		printf("%d\n",n/k-1);
	}
}
