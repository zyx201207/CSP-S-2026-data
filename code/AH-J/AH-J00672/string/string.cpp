#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
struct p
{
    ll x;
    char y;
}a[200005],b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i].x);
        cin>>a[i].y;
    }
    for(ll i=1;i<=n;i++)
    {
        b[i].x=a[n-i+1].x;
        b[i].y=a[n-i+1].y;
    }
    ll i=1,j=1;
    while(i<=n&&j<=n)
    {
        ll u=a[i].x,v=b[j].x;
        char l=a[i].y,r=b[j].y;
        if(u>v)
        {
            if(l!=r) k+=v;
            a[i].x-=v;
            j++;
        }
        else if(u<v)
        {
            if(l!=r) k+=u;
            b[j].x-=u;
            i++;
        }
        else
        {
            if(l!=r) k+=u;
            i++;
            j++;
        }
    }
    cout<<k/2;
    return 0;
}
