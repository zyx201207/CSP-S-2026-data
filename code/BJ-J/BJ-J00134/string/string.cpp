#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
char c[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    int l=1,r=n,ans=0;
    while(l<r)
    {
        if(a[l]<a[r])
        {
            if(c[l]!=c[r]) ans+=a[l];
            a[r]-=a[l];
            a[l]=0;
        }
        else if(a[l]>a[r])
        {
            if(c[l]!=c[r]) ans+=a[r];
            a[l]-=a[r];
            a[r]=0;
        }
        else 
        {
            if(c[l]!=c[r]) ans+=a[l];
            a[l]=0;
            a[r]=0;
        }
        if(a[l]==0) l++;
        if(a[r]==0) r--;
    }
    cout<<ans;
    return 0;
}