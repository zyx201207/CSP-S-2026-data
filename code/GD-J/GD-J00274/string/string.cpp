#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef char ch;
typedef string str;
const ll maxn=2e5+1;
ll n,a[maxn],l,lc,r,rc,ans;
ch c[maxn];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    l=1,r=n,lc=1,rc=a[n];
    while(l<r)
    {
        ll val=min(a[l]-lc+1,rc);
        lc+=val,rc-=val;
        if(c[l]!=c[r]) ans+=val;
        if(lc==a[l]+1) l++,lc=1;
        if(!rc) r--,rc=a[r];
    }
    cout<<ans;
}