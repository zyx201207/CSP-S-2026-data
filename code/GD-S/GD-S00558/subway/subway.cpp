#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD=1e9+7;
const ll MAXN=5e5+5;
const ll inf=LONG_LONG_MAX;
struct node
{
	ll to,val;
};
ll n,m,T,a[MAXN],ed[505][505];
vector<node>b[MAXN];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	cin>>n>>m;
	cin>>T;
	cin>>T;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)ed[i][j]=1e15;
		}
	}
	for(int i=1;i<=n;i++)
	{
		ll q;
		cin>>q;
		while(q--)
		{
			ll w,e;
			cin>>w>>e;
			b[w].push_back({i,e});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto q:b[i])
		{
			for(auto w:b[i])
			{
				ed[q.to][w.to]=min(ed[q.to][w.to],q.val+w.val);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				ed[j][k]=min(ed[j][k],ed[j][i]+ed[i][k]);
			}
		}
	}
	while(T--)
	{
		ll l,r,ans=inf;
		cin>>l>>r;
		for(auto q:b[l])
		{
			for(auto w:b[r])
			{
				ans=min(ans,q.val+w.val+ed[q.to][w.to]);
			}
		}
		ans+=a[l]+a[r];
		cout<<ans<<"\n";
	}
	return 0;
}
