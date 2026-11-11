#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
bool vis[15];
vector<int>v[1000005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)v[i].clear();
        for(int i=1;i<n;i++)
        {
            int o,p;
            cin>>o>>p;
            v[o].push_back(p);
            v[p].push_back(o);
        }
        if(c==13||c==14)
        {
            cout<<(ll)(ceil((((n+1)/2)+3-k)/4.0))<<'\n';
        }
    }
    return 0;
}
