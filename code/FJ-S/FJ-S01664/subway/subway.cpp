#include<bits/stdc++.h>
using namespace std;
long long n,m,d,q,w[500001],k[501],d1[501][501];
vector<pair<int,long long>> e1[500001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int c=1;c<=m;c++)
	{
		cin>>w[c];
	}
	memset(d1,0x3f,sizeof(d1));
	for(int c=1;c<=n;c++)
	{
		cin>>k[c];
		for(int i=1;i<=k[c];i++)
		{
			int aa,tt;
			cin>>aa>>tt;
			e1[aa].push_back({c,tt});
		}
		d1[c][c]=0;
	}
	for(int c=1;c<=m;c++)
	{
		for(auto i:e1[c])
		{
			for(auto j:e1[c])
			{
				if(i.first==j.first) continue;
				d1[i.first][j.first]=d1[j.first][i.first]=min(d1[i.first][j.first],i.second+j.second);
			}
		}
	}
	for(int j=1;j<=n;j++)
	{
		for(int c=1;c<=n;c++)
		{
			for(int i=1;i<=n;i++)
			{
				d1[c][i]=min(d1[c][i],d1[c][j]+d1[j][i]);
			}
		}
	}
	for(int c=1;c<=q;c++)
	{
		int x,y;
		long long ans=1e18;
		cin>>x>>y;
		for(auto i:e1[x])
		{
			for(auto j:e1[y])
			{
				ans=min(ans,w[x]+w[y]+d1[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
