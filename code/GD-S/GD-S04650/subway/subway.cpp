#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=505,M=1005;
ll c,n,m,d,q;
ll w[M],k[N];
ll dis[M][M];
vector<ll>a[N],t[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dis,0x3f3f3f3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++)
		{
			ll x;
			cin>>x;
			a[i].push_back(x);
			cin>>x;
			t[i].push_back(x);
		}
		for(int j=1;j<=k[i];j++)
		{
			for(int jj=1;jj<j;jj++)
			{
				dis[a[i][j]][a[i][jj]]=dis[a[i][jj]][a[i][j]]=
				min(dis[a[i][j]][a[i][jj]],t[i][j]+t[i][jj]);
			}
		}
	}
	for(int mid=1;mid<=m;mid++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dis[i][j]=dis[j][i]=
				min(dis[i][j],dis[i][mid]+dis[mid][j]);
			}
		}
	}
	
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		if(x==y)cout<<"0\n";
		else cout<<dis[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}












