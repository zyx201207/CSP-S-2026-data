#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
ll c,n,m,d,q;
ll w[505];
vector<pll>v[505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    if(7<=c<=11)
    {
        for(int i=0;i<m;i++)
        {
            cin>>w[i];
        }
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            for(int j=0;j<x;j++)
            {
                ll y,z;
                cin>>y>>z;
                pll b;
                b.first=y;
                b.second=z;
                v[i].push_back(b);
            }
        }
        for(int i=0;i<q;i++)
        {
            ll x,y;
            cin>>x>>y;
            ll ans=w[x];
            while(x!=y)
            {
                for(int i=0;i<n;i++)
                {
                    if(v[i][0].first==x)
                    {
                        ans+=v[i][0].second;
                        x=v[i][1].first;
                    }
                    if(v[i][1].first==x)
                    {
                        ans+=v[i][1].second;
                        x=v[i][0].first;
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                if(v[i][0].first==x)
                {
                    ans+=v[i][0].second;
                    x=v[i][1].first;
                }
                if(v[i][1].first==x)
                {
                    ans+=v[i][1].second;
                    x=v[i][0].first;
                }
            }
            cout<<ans+w[y];
        }
    }
    return 0;
}
//Don't sell this for Gaode
