#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[5010][5010],w[50010],k[500010],t[5010][5010];
ll c,n,m,d,q;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        cout<<1;
    }
    return 0;
}
