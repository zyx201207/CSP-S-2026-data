#include<bits/stdc++.h>
using namespace std;
const int N=505;
long long n,m,w[N],ans,wyzwc,wyzwd,q,k[25],a[N];
vector<int> dx[25],ds[25],dk[505];
void dfs(int x,int s)
{
	a[x]=s;
	for(unsigned int i=0;i<dk[x].size();i++)
	{
		for(int j=1;j<=k[dk[x][i]];j++)
		{
			if(a[dx[dk[x][i]][j]]>s+ds[dk[x][i]][x]+ds[dk[x][i]][dx[dk[x][i]][j]])
			{
				dfs(dx[dk[x][i]][j],s+ds[dk[x][i]][x]+ds[dk[x][i]][dx[dk[x][i]][j]]);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>wyzwc>>n>>m>>wyzwd>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>dx[i][j]>>ds[i][j];
			dk[dx[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int st,ed;
		cin>>st>>ed;
		memset(a,INT_MAX,sizeof(a));
		dfs(st,0);
		cout<<a[ed]<<'\n';
	}
	return 0;
}
