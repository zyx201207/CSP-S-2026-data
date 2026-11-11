#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5+10;
int n, m;
int a[N];

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >>n >>m;
    for(int i=1; i<=n; i++)
        cin >>a[i];
    sort(a+1, a+n+1);
    int ans=0, l=1, s=0;
    for(int r=1; r<=n; r++)
    {
        s += (r-l)*(a[r]-a[r-1]);
        while(l<r && s>m)
        {
            s-=(a[r]-a[l]);
            l++;
        }
        if(s <= m)
            ans = max(ans, r-l+1);
    }
    cout <<ans <<endl;
    return 0;
}