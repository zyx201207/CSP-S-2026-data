#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int c,n,m,d,q,a[22][N],k[22],l,r;
long long v[22][N],ans,w[N];
bool b[22][N];
void dfs(int x,int y,long long z)
{
	if(y==r)
	{
		ans=min(ans,z);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i][y]!=0 && !b[i][y])
		{
			b[i][y]=1;
			dfs(i,y,z+v[i][y]);
			b[i][y]=0;
		}
	}
	for(int i=1;i<=k[x];i++)
	{
		if(v[x][a[x][i]]!=0 && !b[x][a[x][i]])
		{
			b[x][a[x][i]]=1;
			dfs(x,a[x][i],z+v[x][a[x][i]]);
			b[x][a[x][i]]=0;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1,t;j<=k[i];j++)
		{
			cin>>a[i][j]>>t;
			v[i][a[i][j]]=t;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		ans=1e9;
		memset(b,0,sizeof(b));
		for(int j=1;j<=n;j++)
			if(v[j][l])
				dfs(j,l,v[j][l]);
		cout<<ans+w[l]+w[r]<<"\n";
	}
	return 0;
}
