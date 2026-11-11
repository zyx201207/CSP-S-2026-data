#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MAXM=5e5+5;
const ll MAX=1e7;

ll c,n,m,d,q,head[MAXM],w[MAXM],x,a,b;
struct edge
{
	ll to,next,num;
}e[MAX];
struct plat
{
	ll t,pnum;
}l,r;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(head,-1,sizeof(head));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x>>l.pnum>>l.t;
		for(int j=2;j<=x;j++)
		{
			cin>>r.pnum>>r.t;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>a>>b;
		cout<<w[a]+w[b]<<endl;
	}
	return 0;
}
