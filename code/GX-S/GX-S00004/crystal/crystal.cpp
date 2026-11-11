#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll sum;
ll m,n,_min;
ll a[500005];
ll cha[500005];
bool cmp(ll x,ll y)
{
    return x<=y;
}
ll sum_cha(ll x,ll y)
{
    for(ll p=x;p<=y;p++)
    {
        sum+=cha[y]-cha[p];
    }
    return sum;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(ll i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(ll i=1;i<=n-1;i++)
    {
        cha[i]=a[i]-a[1];
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i;j<=n-1;j++)
        {
            if(sum_cha(i,j)<=m)
            {
                _min=max((j-i+1),_min);
            }
            sum=0;
        }
    }
    cout << _min;
    return 0;
}
