#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
ll n,m,a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    map<ll,ll> v;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++)
    {
        map<ll,ll> mp;
        for(int j=i; j<=n; j++)
        {
            if(mp[a[j]]) mp.clear();
            mp[a[j]]=1;
        }
        for(int j=1; j<=m; j++)
        {
            if(mp[j]==1) v[j]++;
        }
        mp.clear();
    }
    for(int i=1; i<=m; i++) cout<<v[i]<<' ';
    return 0;
}
