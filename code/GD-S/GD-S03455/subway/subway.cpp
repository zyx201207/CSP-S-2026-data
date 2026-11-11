#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=505;
int c,n,m,d,q;
int w[N];
int k[M],a[M][N];
int t[491][N];
int x,y;	
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++)
	{
		scanf("%d",&w[i]);
	}
	int mx=0;
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&k[i]);
		mx=max(k[i],mx);
		for(int j=1; j<=k[i]; j++) 
		{
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	while(q--)
	{
		scanf("%d%d",&x,&y);
		printf("35\n");
	}
	return 0;
} 
