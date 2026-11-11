#include<bits/stdc++.h>
using namespace std;
long long a[510][510];
int w[500010];
vector<pair<int,long long> >t[500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			long long x,y;
			cin>>x>>y;
			t[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=m;i++)
	{
		for(auto it=t[i].begin();it!=t[i].end();it++)
		{
			for(auto jt=(it);jt!=t[i].end();jt++)
			{
				a[(*it).first][(*jt).first]=min(a[(*it).first][(*jt).first],(*it).second+(*jt).second);
				a[(*jt).first][(*it).first]=a[(*it).first][(*jt).first];
			}
		}
	}
	for(int i=1;i<=n;i++)a[i][i]=0;
	for(int i=1;i<=n;i++)for(int k=1;k<=n;k++)for(int j=1;j<=n;j++)a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(auto it=t[x].begin();it!=t[x].end();it++)
		{
			for(auto jt=t[y].begin();jt!=t[y].end();jt++)
			{
				ans=min(ans,(*it).second+(*jt).second+a[(*it).first][(*jt).first]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
