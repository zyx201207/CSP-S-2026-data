#include<bits/stdc++.h>
using namespace std;

struct st{
	int to,val;
};
int c,n,m,q,d,mm[100005],t[100005],a[100005],ans;
vector<st> g[100005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>mm[i];
	int dis[m+1][m+1];
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[k]>>t[k];
		for(int l=1;l<=k;l++)
		{
			for(int o=l+1;o<=k;o++)
			{
				dis[a[l]][a[o]]=dis[a[o]][a[l]]=min(t[l]+t[o],dis[a[l]][a[o]]);
			}
		}
	}
	for(int kk=1;kk<=m;kk++)
	{
		for(int i=1;i<=m;i++)
		{
			if(kk==i) break;
			for(int j=1;j<=m;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][kk]+dis[kk][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+mm[x]+mm[y]<<'\n';
	}
	
	return 0;
}
