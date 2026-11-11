#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,a[N],ans=0,l,r,sl,sr;
char c[N];

signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i]>>c[i];
    l=1,r=n;
    sl=a[1],sr=a[n];
    while (l<=r)
    {
        int k=min(sl,sr);
        if (c[l]!=c[r]) ans+=k;
        sl-=k,sr-=k;
        if (!sl) l++,sl=a[l];
        if (!sr) r--,sr=a[r];
    }
    cout<<ans;
    return 0;
}
