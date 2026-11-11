#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const int N=505,M=500005;
const ll inf=1e17;
ll c,n,m,d,q;
ll dis[N][N],w[M];
vector<pii> a[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int num;
		cin>>num;
		for(int j=1;j<=num;j++)
		{
			int x,y;
			cin>>x>>y;
			a[x].push_back(pii(i,y));
		}
	}
	memset(dis,0x3f,sizeof(dis)); 
	for(int i=1;i<=m;i++)
	{
		for(pii j:a[i])
		{
			for(pii k:a[i])
			{
				dis[j.first][k.first]=dis[k.first][j.first]=min(dis[k.first][j.first],j.second+k.second);
			}
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++) cout<<dis[i][j]<<" ";
//		cout<<"\n";
//	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(pii i:a[x])
		{
			for(pii j:a[y])
			{
				ans=min(ans,w[x]+w[y]+i.second+j.second+dis[i.first][j.first]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
