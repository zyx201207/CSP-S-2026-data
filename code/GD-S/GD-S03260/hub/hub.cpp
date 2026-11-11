#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
bool G[15];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	for(scanf("%d%d",&c,&t);t--;)
	{
		scanf("%d%d",&n,&k);
		for(int i=1,u,v;i<n;i++)
			scanf("%d%d",&u,&v);
		printf("%d\n",k-1);
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
