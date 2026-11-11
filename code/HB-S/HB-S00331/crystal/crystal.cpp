#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,m,a[N],s[N],r=1,ans=0;

bool check (int l,int r)
{
    int k=a[r]*(r-l+1)-s[r]+s[l-1];
   // printf("{%d %d %d}\n",l,r,k);
    return k<=m;
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for (int i=1;i<=n;i++)
    {
        r=max(r,i);
        while (r<n&&check(i,r+1)) r++;
        ans=max(ans,r-i+1);
    }
    cout<<ans;
    return 0;
}
