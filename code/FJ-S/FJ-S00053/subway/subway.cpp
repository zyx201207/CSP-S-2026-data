#include<bits/stdc++.h>
using namespace std;
const int N=505,M=500005;
#define ll long long
ll w[M];
int bl[M][21],tot[M];
ll t[M][21];
ll d[N][N];
const ll inf=1e18;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int id,n,m,D,Q;
	scanf("%d%d%d%d%d",&id,&n,&m,&D,&Q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int x;
			ll tm;
			scanf("%d%lld",&x,&tm);
			tot[x]++;
			bl[x][tot[x]]=i;
			t[x][tot[x]]=tm;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=inf;
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=tot[i];j++)
		{
			for(int k=j+1;k<=tot[i];k++)
			{
				ll tmp=t[i][j]+t[i][k];
				d[bl[i][j]][bl[i][k]]=min(d[bl[i][j]][bl[i][k]],tmp);
				d[bl[i][k]][bl[i][j]]=min(d[bl[i][k]][bl[i][j]],tmp);
			}
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++) cout << d[i][j] << ' ';
//		cout << endl;
//	}
	while(Q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=inf;
		for(int i=1;i<=tot[x];i++) for(int j=1;j<=tot[y];j++)
		{
//			cout << bl[x][i] << ' ' << bl[y][j] << ' ' << d[bl[x][i]][bl[y][j]]+t[x][i]+t[y][j] << endl;
			ans=min(ans,d[bl[x][i]][bl[y][j]]+t[x][i]+t[y][j]);
		}
//		cout << ans << endl;
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
