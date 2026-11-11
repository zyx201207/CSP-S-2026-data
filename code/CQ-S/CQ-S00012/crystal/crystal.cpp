#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=5e5+10;
int a[N],s[N];
int n,m;
int check(int l,int r)
{
    return (r-l+1)*a[r]-s[r]+s[l-1];
}
void solve()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    // int ans=0;
    // for (int R=1;R<=n;R++)
    // {
    //     int l=1,r=R,idx=inf;
    //     while (l<=r)
    //     {
    //         int mid=l+(r-l)/2;
    //         if ((R-mid+1)*a[R]-s[R]+s[mid-1]<=m)
    //         {
    //             r=mid-1;
    //             idx=mid;
    //         }
    //         else
    //         {
    //             l=mid+1;
    //         }
    //     }
    //     if (R-idx+1==4236)
    //     {
    //         cerr<<idx<<' '<<R<<'\n';
    //     }
    //     ans=max(ans,R-idx+1);
    // }
    // cout<<ans<<'\n';
    int r=1,temp=0,res=0;
    for (int l=1;l<=n;l++)
    {
        r=max(l,r);
        while (r<n&&check(l,r+1)<=m)
        {
            r++;
        }
        // cerr<<l<<' '<<r<<'\n';
        res=max(res,r-l+1);
        // if (r-l+1==4236)
        // {
        //     cerr<<l<<' '<<r<<'\n';
        //     cerr<<check(l,r)<<'\n';
        // }
    }
    cout<<res<<'\n';
    return;
}
signed main()
{
    // freopen("crystal/crystal4.in","r",stdin);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TestCase=1;
    // cin>>TestCase;
    for (int CaseId=1;CaseId<=TestCase;CaseId++)
    {
        solve();
    }
    return 0;
}

/*
g++ crystal.cpp -o crystall -std=c++14 -O2
./crystall
*/