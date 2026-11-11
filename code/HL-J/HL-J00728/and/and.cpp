#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    ll sum=0;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    for(ll i=1;i<=n;i++)
        if(a[i]%2==0)
            sum=1;
    sort(a+1,a+n+1);
    ll q=a[n]+1,summ=0;
    while(q==1)
    {
        if(q%2!=0)
        {
            summ=1;
            break;
        }
        q/=2;
    }

    if(m==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(m==n)
    {
        ll b=a[1];
        for(ll i=2;i<=n;i++)
            b=a[i]&b;
        cout<<b;
        return 0;
    }
    if(m== 2)
    {
        ll b=a[n]&a[n-1];
        cout<<b;
        return 0;
    }
    if(sum==0&&summ==0)
    {
        for(ll i=n;i>=1;i--)
        {
            if(i= n-m+1)
            {
                cout<<a[i];
                return 0;
            }

        }
    }
    ll b=a[n];
    for(ll i=n-1;i>=1;i--)
    {
        if(i==n-m+1)
        {
            cout<<b;
            return 0;
        }
        b=a[i]&b;
    }
    return 0;
}
