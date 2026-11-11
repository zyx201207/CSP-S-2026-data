#include<bits/stdc++.h>
#define L return
#define P 0
#define C ;
using namespace std;
const int N=510,M=500010;
int cc,n,m,d,T;
int w[M],a[N][N],t[N][N],k[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&cc,&n,&m,&d,&T);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	while(T--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		
	}
	
	L P C
}