#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t;
int ct[500078];
vector<int>a[510];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>ct[i];
	for(int i=0;i<n;i++)
	{
		int z;
		cin>>z;
		for(int j=0;j<z;j++)
		{
			int zz;
			cin>>zz;
			a[i].push_back(zz);
			cin>>t;
		}
	}
	int st,en,ans;
	while(q--)
	{
		ans=0;
		cin>>st>>en;
		ans+=ct[st]+ct[en];
		int dp[m];
		memset(dp,0,sizeof(dp));
		while(dp[en]==0)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<a[i].size();j++)
				{
					dp[a[i][j]]=dp[st]+1;
					st=a[i][j];
				}
			}
		}
		ans+=t*(dp[en]-1);
		cout<<ans<<'\n';
	}
}
