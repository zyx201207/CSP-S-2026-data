#include <bits/stdc++.h>
#define int long long
#define loop(a,b) for (int a = 1 ; a <= b ; ++a)
#define lop(a,b,c) for (int a = b ; a <= c; ++a)
using namespace std;
int a[500005];
int n,m;
bool check(int x)
{
    int l=1,r=x,s=0;
    loop(i,x) s+=a[i];
    while (r<=n)
    {
        if (x*a[r]-s<=m)
        {
            return 1;
        }
        s-=a[l++];
        s+=a[++r];
    }
    return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    loop(i,n)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n,mid,ans=1;
    while (l<=r)
    {
        mid=(l+r)>>1;
        if (check(mid))
        {
            ans=mid;
            l=mid+1;
        } else {
            r=mid-1;
        }
    }
    cout << ans << endl;
    return 0;
}
