#include<bits/stdc++.h>
using namespace std;
long long x,y;
long long c,n,m,d,q;
long long w[500003];
long long k[503];
vector <long long> jing [500003];
vector <long long> jiao[503][503];
long long  u[500003][503];
vector <long long> a[503];
vector <long long> t[503];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++)
	{
		cin>>k[i];
		long long a1,b1;
		for(long long j=1;j<=k[i];j++)
		{
			cin>>a1>>b1;
			jing[a1].push_back(i);
			for(long long r : jing[a1])
			{
				jiao[i][r].push_back(a1);
				jiao[r][i].push_back(a1);
			}
			a[i].push_back(a1);
			t[i].push_back(b1);
			u[a1][i]=b1;
		}
	}
	long long ans=INT_MAX;
	for(long long ch=1;ch<=q;ch++)
	{
		cin>>x>>y;
		for(int i : jing[x])
		{
			for(int j : jing[y])
			{
				if(!jiao[i][j].empty())
				{
					for(int r : jiao[i][j])
					{
						ans=min(ans,u[r][i]+u[r][j]);
					}
				}
				if(i==j) ans=0;
			}
		}
		cout<<ans+w[x]+w[y];
	}
	return 0;
}
