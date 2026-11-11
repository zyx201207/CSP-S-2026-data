#include<bits/stdc++.h>
using namespace std;

long long wa[501][10086],ss[10086],w2[501][10086],ste[2][10086],a,b,c,d,e,f,g;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	for(int i=0;i<c;i++)
	{
		scanf("%d",&ss[i]);
	}
	for(int i=0;i<b;i++)
	{
		scanf("%d",&a);
		for(int j=0;j<a;j++)
		{
			scanf("%d%d",&wa[i][j],&w2[i][j]);
		}
	}
	for(int i=0;i<e;i++)
	{
		scanf("%d%d",&ste[1][i],&ste[2][i]);
	}
	for(int i=0;i<e;i++)
	{
		printf("%d\n",ss[ste[1][i]]+ss[ste[2][i]]);
	}
	return 0;
}
