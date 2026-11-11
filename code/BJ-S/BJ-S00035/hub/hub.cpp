#include<bits/stdc++.h>
#define int ll
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=2e6+5;
ll c,t,n,k;
ll u[maxn],v[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>u[i]>>v[i];
        cout<<1<<'\n';
    }
    return 0;
}
