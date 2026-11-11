#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll c,T,n,d,a[2000010];
map<pair<ll,ll>,ll>mp;

void bfs()
{
	queue<pair<ll,ll> >q;
	for(int i=1;i<=n;i++)
	while(!q.empty())
	{
		ll u=q.front();
		q.pop();
		for(int v=u+1;v<=n;v++)
		{
			if(a[v]-a[u]<=d)
			{
				if(mp[{u,v}]==0)
				{
					mp
				}
			}
			else
			{
				break;
			}
		}
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>c>>T;
	while(T--)
	{
		mp.clear();
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		bfs();
	}

	return 0;
}
