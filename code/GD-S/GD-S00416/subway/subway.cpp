#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const ll M=5e5+5,N=505;
ll c,n,m,d,Q,w[M];
vector<pair<ll,ll> >v[M];
ll f[N][N];
bool us[M];
ll q[M],pl;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	memset(f,0x7f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		ll len;
		cin>>len;
		while(len--)
		{
			ll x,y;
			cin>>x>>y;
			v[x].push_back({i,y});
			if(!us[x]&&v[x].size()>1)
			{
				q[++pl]=x;
				us[x]=1;
			}
		}
		f[i][i]=0;
	}
	for(int i=1;i<=pl;i++)
	{
		ll x=q[i];
		for(auto op:v[x])
		{
			for(auto ol:v[x])
			{
				ll l=op.first,r=ol.first;
				if(l==r) continue;
				f[l][r]=f[r][l]=min(f[l][r],op.second+ol.second);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(f[i][k]==f[0][0]) continue;
			for(int j=1;j<=n;j++)
			{
				if(f[j][k]==f[0][0]) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(Q--)
	{
		ll x,y,ans=LLONG_MAX;
		cin>>x>>y;
		for(auto op:v[x])
		{
			for(auto ol:v[y])
			{
				ll l=op.first,r=ol.first;
				if(f[l][r]==f[0][0]) continue;
//				cout<<l<<" "<<r<<endl;
				ans=min(ans,f[l][r]+op.second+ol.second);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
