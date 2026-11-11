#include<bits/stdc++.h>
using namespace std;
using i64=int64_t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,x,y,minn=INT_MAX;
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+1),tp(m+1);
	vector<vector<int>> t(n+1,vector<int>(m+1));
	for (int i=1;i<=m;i++)
		cin>>w[i];
	for (int i=1,k;i<=n;i++)
	{
		cin>>k;
		for (int j=1,u;j<=k;j++)
		{
			cin>>u;
			cin>>t[i][u];
			if (tp[u]) 
			{
				tp[u]=3;
				minn=min(minn,t[1][u]+t[2][u]);
			}
			else tp[u]=i;
		}
	}
	if (c==20||c==21)
	{
		while (q--)
		{
			cin>>x>>y;
			i64 ans=w[x]+w[y];
			if (tp[x]==3&&tp[y]!=3) ans+=min(t[tp[y]][x]+t[tp[y]][y],t[3-tp[y]][x]+t[tp[y]][y]+minn);
			else if (tp[y]==3&&tp[x]!=3) ans+=min(t[tp[x]][y]+t[tp[x]][x],t[3-tp[x]][y]+t[tp[x]][y]+minn);
			else if (tp[x]==tp[y]&&tp[x]==3)
			{
				int tmp=min({t[1][x]+t[1][y],t[2][x]+t[2][y],min(t[1][x]+t[2][y],t[2][x]+t[1][y])+minn});
				ans+=tmp;
			}
			else if (tp[x]==tp[y]) ans+=t[tp[x]][x]+t[tp[y]][y];
			else ans+=t[tp[x]][x]+t[tp[y]][y]+minn;
			cout<<ans<<'\n';
		}
	}
}
