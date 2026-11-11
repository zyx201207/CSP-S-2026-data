#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500010], s[500010];
bool check(int mid)
{
    int l=1;
    for(int r=mid;r<=n;r++, l++)
    {
        if((r-l)*a[r]-(s[r-1]-s[l-1])<=m)
        {
            // cout<<r<<' '<<(r-l)*a[r]-(s[r-1]-s[l-1])<<endl;
            return true;
        }
    }
    return false;
}
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        // cout<<a[i]<<' ';
    }
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<s[i]<<' ';
    // }
    // cout<<endl;
    int l=1, r=n, ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        // cout<<l<<' '<<r<<' '<<mid<<endl;
        if(check(mid))
        {
            // cout<<"yyyy"<<endl;
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
            // cout<<"nono"<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
/*
5 9
3 10 13 15 2
*/