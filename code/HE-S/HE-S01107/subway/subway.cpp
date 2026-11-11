#include <bits/stdc++.h>
using namespace std;
int C,n,m,z,q,w[500010],a,b[510][500010],r1,d[510][510];
struct dot{
	int t[30],s;
}c[500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin.tie(0);
//	cout.tie(0);
	cin>>C>>n>>m>>z>>q;
	for(int i = 1;i<=m;i++)cin>>w[i];
	for(int i = 1;i<=n;i++)
	{
		cin>>r1;
		while(r1--)
		{
			cin>>a;
			c[a].t[++c[a].s]=i;
			cin>>b[i][a];
		}
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(i!=j)d[i][j]=-1;
		}
	}
	for(int i = 1;i<=m;i++)
	{
		for(int j = 1;j<=c[i].s;j++)
		{
//			cout<<b[c[i].t[j]][i]<<" ";
			for(int k = j+1;k<=c[i].s;k++)
			{
				if(d[c[i].t[j]][c[i].t[k]]==-1)d[c[i].t[j]][c[i].t[k]]=b[c[i].t[j]][i]+b[c[i].t[k]][i];
				else d[c[i].t[j]][c[i].t[k]]=min(d[c[i].t[j]][c[i].t[k]],b[c[i].t[j]][i]+b[c[i].t[k]][i]);
				d[c[i].t[k]][c[i].t[j]]=d[c[i].t[j]][c[i].t[k]];
			}
		}
//		cout<<endl;
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(i==j)continue;
			for(int k = 1;k<=n;k++)
			{
				if(d[k][j]!=-1&&d[i][k]!=-1&&k!=i&&k!=j)
				{
					if(d[i][j]!=-1)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
					else d[i][j]=d[i][k]+d[k][j];
					d[j][i]=d[i][j];
				}
			}
		}
	}int r2,ans;
	while(q--)
	{
		ans=1e9+7;
		cin>>r1>>r2;
		if(r1==r2)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i = 1;i<=c[r1].s;i++)
		{
			for(int j = 1;j<=c[r2].s;j++)
			{
				ans=min(ans,d[c[r1].t[i]][c[r2].t[j]]+b[c[r1].t[i]][r1]+b[c[r2].t[j]][r2]);
			}
		}ans+=w[r1]+w[r2];
		cout<<ans<<endl;
	}
	return 0;
} 
