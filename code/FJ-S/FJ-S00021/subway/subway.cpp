#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,q,w[5000005],k[555],x,y,ans;
struct sub{
	ll a;
	ll t;
};
vector<sub> v[1010];//v[i][j]代表第i号线经过地铁站a[j]的时间t[j] 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=0;i<m;i++)
	{
		cin>>w[i];
	}
	for(ll i=0;i<n;i++)
	{
		cin>>k[i];
		for(ll j=0;j<k[i];j++)
		{
			ll e,r;
			cin>>e>>r;
			v[i].push_back({e,r});
		}
	}
	for(ll i=0;i<q;i++)
	{
		ans=0;
		cin>>x>>y;
		ll now_s=x;
		ans+=w[x-1]+w[y-1];
		while(1)
		{
			for(ll j=0;j<n;j++)
			{
				for(ll l=0;l<v[j].size();l++)
				{
					if(v[j][l].a==now_s)
					{
						if(l==0)
						{
							ans+=v[j][l].t+v[j][l+1].t;
							now_s=v[j][l+1].a;
						}
						else
						{
							ans+=v[j][l].t+v[j][l-1].t;
							now_s=v[j][l-1].a;
						}
						break;
					}
				}
			}
			if(now_s==y)
			{
				cout<<ans<<endl;
				break;
			}
		}
	}
	return 0;
}
