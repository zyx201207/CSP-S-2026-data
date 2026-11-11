#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<ll> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    ll res=0;
    for(int i=30 ; i>=0;--i)
    {
        ll tmp = res | (1LL<<i);
        int cnt=0;
        for(ll x : a)
        {
            if((x&tmp)==tmp) cnt++;
        }
        if(cnt>=m) res=tmp;
    }
    cout<<res;
    return 0;
}
