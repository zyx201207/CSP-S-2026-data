#include<bits/stdc++.h>
using namespace std;
long long vec[505][505],w[500005];
vector<pair<long long,long long>> t[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,m,n,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			vec[i][j]=LLONG_MAX;
		}
		vec[i][i]=0;
	}
	long long sum=m;
	for(int i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		long long lst=0;
		for(int j=1;j<=k;j++)
		{
			long long a1,t1;
			cin>>a1>>t1;
			if(!t[a1].empty())
			{
				for(auto z:t[a1])
				{
					vec[i][z.first]=vec[z.first][i]=min(vec[i][z.first],t1+z.second);
				}
			}
			t[a1].push_back({i,t1});
		}
		sum+=m;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(vec[i][k]!=LLONG_MAX&&vec[k][j]!=LLONG_MAX&&i!=j)
				{
					vec[i][j]=min(vec[i][j],vec[i][k]+vec[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		long long ans=LLONG_MAX;
		for(auto a:t[x])
		{
			for(auto b:t[y])
			{
				ans=min(ans,vec[a.first][b.first]+w[x]+a.second+b.second+w[y]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 

