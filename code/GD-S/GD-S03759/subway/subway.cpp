#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> t[500005],a[500005],v[500005];
int c,n,m,k,d,q,x,y,l,r,mid,ans,b[500005],q[500005],f[505][1005];
int dfs(int st,int sum)
{
	q[st]=1;
	for(int i=1;i<=n;i++)
	{
		if(f[i][st])
		{
			for(int j=0;j<t[i].size();j++) if(!q[t[i][j]]) dfs(t[i][j],sum+) 
		}
	}
}
signed main()
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x>>y;
			t[i].push_back(x),a[i].push_back(y),f[i][x]=1;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		dfs(l,b[l]);
	}
}
