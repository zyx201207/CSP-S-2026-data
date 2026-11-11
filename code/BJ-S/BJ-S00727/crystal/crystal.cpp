#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[500005];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    int wei=1;
    int num=0;
    int ans=0;
    for (int i=2;i<=n;i++)
    {
        num=num+(i-wei)*(a[i]-a[i-1]);
        while (num>m && wei<=i)
        {
            num=num-(a[i]-a[wei]);
            wei++;
        }
        ans=max(ans,i-wei+1);
        //cout << "&&&" << i << " " << wei << " " << num << endl;
    }
    cout << ans << endl;

    return 0;
}
