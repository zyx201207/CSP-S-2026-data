#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)1e5+10
#define ld long long
int w[1000010],a[1010][1010],t[1010][1010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	int k;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for (int j=1;j<=k;j++)
		{
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	int x,y;
	int max=0;
	while (q--)
	{
		scanf("%d%d",&x,&y);
		
	}
	return 0;
}

