#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200010
int n;
ll a[N],c[N];
ll l,r,llen,rlen;
ll ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char ch;
        cin>>a[i]>>ch;
        c[i]=ch-'a';
    }
    l=1,r=n;
    llen=a[l],rlen=a[r];
    while(l<r)
    {
        if(c[l]!=c[r]) ans+=min(llen,rlen);
        if(llen>rlen) r--,llen-=rlen,rlen=a[r];
        else l++,rlen-=llen,llen=a[l];
    }
    cout<<ans;
    return 0;
}