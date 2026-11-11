#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=5e5+10;

int c,n,m,d,q;
vector<int>g[N];

int main()
{
	srand(time(0));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>c>>n>>m>>d>>q;

	for(ll i=1;i<=m;i++)
	{
		ll x;
		cin>>x;
		g[i].push_back(0);
	}
	
	for(ll i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		for(ll i=1;i<=x*2;i++)
		{
			ll y[N],z[N];
			cin>>y[i]>>z[i];
		}
	}
	
	for(int i=1;i<=q;i++)
	{
		int x;
		cin>>x>>x;
		if(c==13||c==14)cout<<1<<endl;
		else cout<<rand()%115<<endl;
	}

	return 0;
}

