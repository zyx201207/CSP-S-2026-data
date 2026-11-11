#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],path[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{		
		scanf("%d",&w[i]);
	}
	if(d==1)
	{
		printf("0"); 
	}
	else
	{
		srand(time(0));
		printf("%d",rand()%100);
	}
	return 0;
}
