#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,k[1024],y,minn;
int w[1024],a[1024][1024],t[1024][1024],dp[1024][1024];
map<int,vector<int>>mp;
void dfs(int step,int cur)
{
	int sstep;
//	cout<<step<<" "<<cur<<" "<<y<<" QWQ\n";
	if(cur>=minn)return;
	if(step==y)
	{
		minn=min(minn,cur);
		return;
	}
	for(int j=0;j<mp[step].size();j++)
	{
		for(int i=1;i<=k[j];i++)
		{
			if(a[j][i]==step)sstep=i;
		}
		for(int i=1;i<=k[j];i++)
		{
			if(a[j][i]!=step)dfs(a[j][i],cur+t[j][sstep]+t[j][i]);
		}
	}return;
}
signed main()
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
			mp[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x;
		cin>>x>>y;
		minn=INT_MAX;
		dfs(x,0);
		cout<<minn+w[x]+w[y]<<'\n';
	}
}
