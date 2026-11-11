#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,a[200005],ans;
char c[200005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    int l=1,r=n;
    while(l<r)
    {
        if(a[l]<=a[r])
        {
            if(c[l]!=c[r]) ans+=a[l];
            a[r]-=a[l];
            a[l]=0;
        }
        else
        {
            if(c[l]!=c[r]) ans+=a[r];
            a[l]-=a[r];
            a[r]=0;
        }
        if(a[l]==0) l++;
        if(a[r]==0) r--;
    }
    cout<<ans<<endl;
    return 0;
}