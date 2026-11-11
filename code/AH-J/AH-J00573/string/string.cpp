#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2*1e5+5;
struct Node{
    ll x;
    char ch;
}a[N];
inline ll abss(ll x)
{
    if(x<0) return -x;
    return x;
}
inline ll maxx(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
inline ll minn(ll a,ll b)
{
    if(a<b) return a;
    return b;
}
ll n,cnt;
ll ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll x;
        char ch;
        cin>>x>>ch;
        if(ch==a[cnt].ch) a[cnt].x+=x;
        else
        {
            a[++cnt].x=x;
            a[cnt].ch=ch;
        }
    }
    ll l=1,r=cnt;
    while(l<r)
    {
        bool lc=false,rc=false;
        ll tmp=min(a[l].x,a[r].x),tl=a[l].x,tr=a[r].x;
        a[l].x=maxx(0,minn(tl-tr,abss(tl-tr)));
        a[r].x=maxx(0,minn(tr-tl,abss(tr-tl)));
        if(a[l].x!=0) lc=1;
        if(a[r].x!=0) rc=1;
        if(a[l].ch!=a[r].ch) ans+=tmp;
        l=l+1-lc,r=r-1+rc;
    }
    cout<<ans<<"\n";
    return 0;
}