#include<bits/stdc++.h>
#define ll long long
using namspace std;
ll n,m,x,h;
int msin()
{
    cin>>n>>m>>x>>h0;
    ll pos=1;
    for(int i=m;i<=n;i++)
    {
        scanf("%lld",&y);
        if(i>x)
        {
            pos++;
        }
        
    }
    ll l=(pos-1)/n+1;
    ll h=(pos-1)%n+1;
    if(1%2==0)
    {
        h=n-h+1;
    }
    cout<<l<<" "<<h<<m;
    return 0;
}
