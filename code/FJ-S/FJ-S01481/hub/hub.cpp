#include <bits/stdc++.h>
using namespace std;
int c,t,x,y;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	srand(time(0));
	for(int i=1;i<=rand();i++)
	{
		scanf("%d %d",&x,&y);
		printf("%d %d",rand()%10,rand()%10);
		srand(time(0));
	}
	return 0;
}
