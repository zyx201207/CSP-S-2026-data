#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+50;
int n,m,d,q,w[N],k[N],a[N][105],t[N][105];
inline int dfs(int start,int end,int xian)
{
	int ans1=0;
	if(start==end)
	{
		ans1+=(t[xian][start]+w[end]);
		return ans1;
	}
	ans1+=t[xian][start];
	for(int i=1;i<=k[xian];++i)
	{
		if(a[xian][i]==end)
		{
			ans1+=(t[xian][end]+w[end]);
			return ans1;
		}
	}
	for(int i=1;i<xian;++i)
	{
		for(int j=1;j<=k[i];++j)
		{
			for(int o=1;o<=k[xian];++o)
			{
				if(a[i][j]==a[xian][o])
				{
					ans1+=dfs(a[i][j],end,i);
				}
			}
		}
	}
	for(int i=xian+1;i<=n;++i)
	{
		for(int j=1;j<=k[i];++j)
		{
			for(int o=1;o<=k[xian];++o)
			{
				if(a[i][j]==a[xian][o])
				{
					ans1+=dfs(a[i][j],end,i);
				}
			}
		}
	}
	return ans1;
} 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int c;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];++j) cin>>a[i][j]>>t[i][a[i][j]];
	}
	for(int i=1;i<=q;++i)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e9;
		for(int j=1;j<=n;++j)
		{
			for(int o=1;o<=k[i];++o)
			{
				if(a[i][j]==x)
				{
					int ans1=dfs(x,y,i)+w[x];
					ans=min(ans,ans1);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
