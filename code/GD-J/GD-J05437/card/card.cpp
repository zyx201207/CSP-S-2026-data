#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		p[a[i]] = i;
	}
	for(int i = 1;i <= m;i++)
	{
		printf("%d ",p[a[i]]);
	}
	return 0;
}
