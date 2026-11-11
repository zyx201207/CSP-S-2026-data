#include<bits/stdc++.h>
using namespace std;
int w[500005],a[505][500005],t[505][500005],k[505];
struct node
{
	int line,t;
};
vector<node> h[25];
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
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
			h[a[i][j]].push_back({i,t[i][j]});
		}
	}
	if(n<=3)
	{
		while(q--)
		{
			int x,y,ans=INT_MAX;
			cin>>x>>y;
			for(auto i:h[x])
			{
				for(auto j:h[y])
				{
					if(i.line==j.line)
					{
						ans=min(ans,(w[x]+w[y]+i.t+j.t));
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
    return 0;
}
