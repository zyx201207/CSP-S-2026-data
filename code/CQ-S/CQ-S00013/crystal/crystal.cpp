#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
关注592080谢谢喵！

预计100+100+56+15=271pts

14:30 看题
14:31 会了，简单二分
14:35 写完了，不对
14:36 改了
14:40 大样例过了，爽，准备拍一下
14:49 拍上了，goto->subway
*/

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<int> a(n+1);
    for (int i=1;i<=n;i++)
        cin>>a[i];

    sort(a.begin()+1,a.end());
    
    for (int i=1;i<=n;i++)
        a[i]+=a[i-1];

    auto check=[&](const int &x,const int &y)->bool
    {
        return (a[y]-a[y-1])*(y-x)-(a[y-1]-a[x-1])<=m;
    };

    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int l=1,r=i-1,res=i;
        while (l<=r)
        {
            int mid=(l+r)>>1;
            if (check(mid,i))
            {
                r=mid-1;
                res=mid;
            }
            else
                l=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans;
}

signed main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifndef LOCAL
        freopen("crystal.in","r",stdin);
        freopen("crystal.out","w",stdout);
    #endif

    int T=1;
    // cin>>T;

    while (T--)
    {
        solve();
        if (T)
            cout<<'\n';
    }
    return 0;
}