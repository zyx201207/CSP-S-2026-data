#include <bits/stdc++.h>
using namespace std;
#define int long long
#define I return
#define AK 0
#define IOI
int a[200005];
char c[200005];
signed main()
{
    /*
    wu ri san xing wu shen:
    kai long long hu?
    xie freopen hu?
    guan tong bu liu hu?
    */
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i]>>c[i];
    }
    int ans = 0, l = 1, r = n;
    while(l <= r)
    {
        if(c[l] != c[r]) ans += min(a[l], a[r]);
        if(a[l] < a[r])
        {
            a[r] -= a[l];
            a[l] = 0;
            l++;
        }
        else
        {
            a[l] -= a[r];
            a[r] = 0;
            r--;
        }
        if(a[l] == 0) l++;
        if(a[r] == 0) r--;
    }
    cout<<ans;
    I AK IOI;
}//mu luogu uid is:1512077