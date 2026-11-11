#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+7;
int c,n,m,d,q;
int w[MAXN];
int k[507];
int a[507][MAXN],t[507][MAXN];
bool e[507][MAXN];
int ans=0;
void dfs(int x,int y,int time)
{
	if(x==y)
	{
		ans=time+w[y];
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(e[x][i]==1) dfs(i,y,time+t[x][x]+t[x][i]);
	}
}
void solve()
{
	int sx,sy;
	cin>>sx>>sy;
	dfs(sx,sy,w[sx]);
	cout<<ans<<endl;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		e[a[i][1]][a[i][2]]=1;
		e[a[i][2]][a[i][1]]=1;
	}
	while(q--)
	{
		solve();
	}
	return 0;
}
 
