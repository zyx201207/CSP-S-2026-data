#include<bits/stdc++.h>
using namespace std;
int w[500005],k[500005],x[500005],y[500005];
int sum[500005];
long long su=0,ans=0;
vector<int> t[505];
long long er=1e18;
struct sa
{
	int a;
	int t;
}at[500005];
int dfs(int x)
{
	if(x==su)
	{
		if(er>ans) er=ans;
		return 0;
	}
	for(int i=0;i<t[x].size();i++)
	{
		if(sum[t[x][i]]==0)
		{
			sum[t[x][i]]=1;
			ans++;
			dfs(t[x][i]);
			sum[t[x][i]]=0;
			ans--;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>at[j].a>>at[j].t;
		}
		for(int j=1;j<=k[i];j++)
		{
			for(int l=1;l<=k[i];l++)
			{
				if(at[j].a!=at[l].a) t[at[j].a].push_back(at[l].a);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		su=y[i];
		dfs(x[i]);
		cout<<at[1].t<<endl;
		cout<<er*2*at[1].t+w[x[i]]+w[y[i]]<<endl;
		er=1e18;
		ans=0;
	}
	return 0;
}
