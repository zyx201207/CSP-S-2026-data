#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=1;
    long long mm=0;
    while(r<n)
    {
        while(mm<=m&&r<n)
        {
            r++;
            mm+=(r-l)*(a[r]-a[r-1]);
        }
        ans=max(r-l,ans);
        while(mm>m)
        {
            l++;
            mm-=a[r]-a[l-1];
        }
        ans=max(r-l+1,ans);
    }
    cout<<ans;
    return 0;
}