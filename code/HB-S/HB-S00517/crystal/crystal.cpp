#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int qzh[500005];
int query(int wei)
{
    int l=1,r=wei,mid=(l+r)>>1ll,re=wei;
    while(l<=r)
    {
        if(a[wei]*(wei-mid+1)-(qzh[wei]-qzh[mid-1])<=m) re=mid,r=mid-1;
        else l=mid+1;
        mid=(l+r)>>1ll;
    }
    return wei-re+1;
}
int ans=1;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) qzh[i]=qzh[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,query(i));
        // cout<<ans<<"\n";
    }
    cout<<ans;
    return 0;
}
/*
5 5
1 2 4 8 9 

5 8
-3 -1 2 2 7

*/