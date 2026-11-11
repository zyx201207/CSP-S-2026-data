#include<bits/stdc++.h>
using namespace std;
char c[200010];
long long a[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++) cin>>a[i]>>c[i];
    long long l=1,r=n,ans=0;
    while(l<=r)
    {
        if(l==r)
        {
            l++;
            continue;
        }
        if(a[l]<=a[r])
        {
            if(c[l]!=c[r]) ans+=a[l];
            a[r]-=a[l];
            a[l]=0;
            l++;
        }
        else
        {
            if(c[l]!=c[r]) ans+=a[r];
            a[l]-=a[r];
            a[r]=0;
            r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
