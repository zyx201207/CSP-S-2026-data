#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
char c[maxn];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int ans=0;
    int l=1,r=n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>c[i];
    }
    while(l+2<=r)
    {
        if(c[l]==c[r])
        {
            if(a[l]<a[r])
            {
                a[r]-=a[l];
                a[l]=0;
                l++;
            }
            else if(a[l]>a[r])
            {
                a[l]-=a[r];
                a[r]=0;
                r--;
            }
            else
            {
                a[l]=0;
                a[r]=0;
                l++;
                r--;
            }
        }
        else
        {
            if(a[l]<a[r])
            {
                ans+=a[l];
                a[r]-=a[l];
                a[l]=0;
                l++;
            }
            else if(a[l]>a[r])
            {
                ans+=a[r];
                a[l]-=a[r];
                a[r]=0;
                r--;
            }
            else
            {
                ans+=a[r];
                a[l]=0;
                a[r]=0;
                l++;
                r--;
            }
        }
        //cout<<ans<<endl;
    }
    if(l<r)
    {
        if(c[l]!=c[r])
        {
            if(a[l]<a[r])
            {
                ans+=a[l];
                a[r]-=a[l];
                a[l]=0;
                l++;
            }
            else if(a[l]>a[r])
            {
                ans+=a[r];
                a[l]-=a[r];
                a[r]=0;
                r--;
            }
            else
            {
                ans+=a[r];
                a[l]=0;
                a[r]=0;
                l++;
                r--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
