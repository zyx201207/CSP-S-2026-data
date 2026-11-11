#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long c,n,m,d,Q,k,a,t,x,y,w[500005],s[505][505];
vector<pair<long long,long long> > q[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(s,0x7f7f7f7f,sizeof(s));
	cin>>c>>n>>m>>d>>Q;
	for(long long i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			cin>>a>>t;
			q[a].push_back({i,t});
		}
		s[i][i]=0;
	}
	for(long long i=1;i<=m;i++)
	{
		sort(q[i].begin(),q[i].end());
		for(long long j=0;j<=(long long)q[i].size()-2;j++)
		{
			for(long long k=j+1;k<=(long long)q[i].size()-1;k++)
			{
				s[q[i][j].first][q[i][k].first]=s[q[i][k].first][q[i][j].first]=min(s[q[i][j].first][q[i][k].first],q[i][j].second+q[i][k].second);
			}
		}
	}
	for(long long k=1;k<=n;k++)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=n;j++)
			{
				if(s[i][k]>1e18||s[j][k]>1e18)
				{
					continue;
				}
				s[i][j]=min(s[i][j],s[i][k]+s[j][k]);
			}
		}
	}
	while(Q--)
	{
		cin>>x>>y;
		long long res=1e18;
		for(auto t:q[x])
		{
			for(auto t2:q[y])
			{
				res=min(res,t.second+t2.second+s[t.first][t2.first]);
			}
		}
		cout<<res+w[x]+w[y]<<endl;
	}
	return 0;
}
