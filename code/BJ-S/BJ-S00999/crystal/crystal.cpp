#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005],m;
int n;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        int l=1,r=i,aa=0;
        while (l<=r)
        {
            int mid=(l+r)/2;
            if (a[i]*(i-mid)-(s[i-1]-s[mid-1])<=m)
            {
                r=mid-1;
                aa=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        ans=max(ans,i-aa+1);
    }
    cout<<ans;
    return 0;
}