#include <bits/stdc++.h>
using namespace std;
#define int long long
#define I return
#define AK 0
#define IOI
int a[500005], s[500005];
bool cmp(int x, int y)
{
    return x > y;
}
signed main()
{
    //wo zhi dao zhe ti shi er fen,dan wo bu hui QwQ
    //min:30+48=78pts
    //max:75+48=123pts
    //my luogu uid is 1512077
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    bool is1 = 1, is2 = 1;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        if(i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) is2 = 0;
    }
    if(is2)
    {
        int g = m / (a[2] - a[1]);
        for(int i = sqrt(2 * g) - 10; i <= sqrt(2 * g) + 10; i++)
        {
            if(i * (i + 1) > 2 * g)
            {
                cout<<i;
                I AK IOI;
            }
        }
    }
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int maxn = 0;
    for(int i = n; i >= 1; i--)
    {
        int g1 = a[i] * i - s[i]- m;
        // cout<<g1<<endl;
        if(g1 <= 0) maxn = max(maxn, i);
        int g = 0;
        /*
        int l = 1, r = n;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(a[i] * mid - s[mid] >= g1) r = mid;
            else l = mid;
        }
        maxn = max(maxn, i - l);
        */
        for(int j = 1; j <= i; j++)
        {
            if(a[i] * j - s[j] >= g1)
            {
                g = j;
                break;
            }
        }
        maxn = max(maxn, i - g);
    }
    cout<<maxn;
    I AK IOI;
}