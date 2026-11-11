#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],ans;
char c[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    for(int l=1,r=n;l<r;)
    {
        if(c[l]!=c[r])
        {
            if(a[l]<a[r])
            {
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }
            else if(a[r]<a[l])
            {
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }
            else
            {
                ans+=a[l];
                l++;
                r--;
            }
        }
        else
        {
            if(a[l]<a[r])
            {
                a[r]-=a[l];
                l++;
            }
            else if(a[r]<a[l])
            {
                a[l]-=a[r];
                r--;
            }
            else
            {
                l++;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
