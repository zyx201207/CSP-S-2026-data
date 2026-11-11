#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m,k;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
    {
        m-=i*(a[i+1]-a[i]);
        if(m<0)
        {
            k=i;
            break;
        }
    }
    cout<<k;
    return 0;
}
