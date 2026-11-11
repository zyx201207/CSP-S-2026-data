//AH-S00977 LSJ Liu Shijie
#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int m,n,c,d,q,w[M],k,a[N][M],t[N][M];
bool f[M];
long long mi;
void dfs(int x,int y,long long tim)
{
	if(x==y)
	{
		mi=min(mi,tim);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=x&&!f[a[i][j]])
			{
				f[a[i][j]]=1;
				dfs(a[i][j],y,tim+t[i][x]+t[i][a[i][j]]);
				f[a[i][j]]=0;
			}
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1,st,en;i<=q;i++)
	{
		memset(f,0,sizeof(f));
		mi=INT_MAX;
		cin>>st>>en;
		dfs(st,en,0);
		cout<<mi+w[st]+w[en]<<"\n";
	}
	return 0;
}
//Oct31==Dec25?
