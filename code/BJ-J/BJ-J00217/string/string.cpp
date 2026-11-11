#include<bits/stdc++.h>
using namespace std;
#define int long long
struct dat{
    int x;
    char c;
} a[200005];
int n,len,ans;
signed main()
{
    int i,j,k,mid,midx,sum=0,l,r,x,d;
    char c;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>x>>c;
        a[i]=dat{x,c};
        len+=x;
    }
    l=1,r=n;
    while (l<r)
    {
        d=min(a[l].x,a[r].x);
        a[l].x-=d;
        a[r].x-=d;
        if (a[l].c!=a[r].c)
            ans+=d;
        if (a[l].x==0)
            l++;
        if (a[r].x==0)
            r--;
    }
    cout<<ans<<endl;
}
