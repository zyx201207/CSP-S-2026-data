#include<bits/stdc++.h>
#define Sum a[i] * (i - 1 - st + 1) - (sum[i - 1] - sum[st - 1])
#define ll long long
using namespace std;
const int N = 5e5 + 7;
ll a[N], d[N], sum[N];
struct node
{
    int l, r;
};
map<ll, node> mp;
int n, m;
int ans;
int main()
{
    freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    mp[a[1]].l = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] != a[i - 1])
        {
            mp[a[i - 1]].r = i - 1;
            mp[a[i]].l = i;
        }
    }
    mp[a[n]].r = n;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, mp[a[i]].r - mp[a[i]].l + 1);
    }
    for (int i =1; i <= n; i++)
    {
        sum[i] += sum[i - 1] + a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        int l = 1, r = i - 1;
        int mid = -1;
        while (l < r)
        {
            int st = l + r>> 1;
            if (Sum <= m)
            {
                mid = st;
                r = st;
            }else
            {
                l = st + 1;
            }

        }
        if (mid == -1)
            continue;
        // now we are change st to i - 1
        if (mp[a[i]].l >= i)
        {
            ans = max(ans,(i - 1) - mid + 1 + (mp[a[i]].r - i + 1));
        }else if (mp[a[i]].l < i)
        {
            ans = max(ans,(mid - 1) - mp[a[i]].l + 1 + (i - 1) - mid + 1 + mp[a[i]].r - i + 1);
        }
        /*
        for (int st = 1; st < i; st++)
        {
            // st to i - 1 all change a[i]
            if (Sum <= m)
            {
                if (mp[a[i]].l >= i)
                {
                    ans = max(ans,(i - 1) - st + 1 + (mp[a[i]].r - i + 1));
                }else if (mp[a[i]].l < i)
                {
                    ans = max(ans,(st - 1) - mp[a[i]].l + 1 + (i - 1) - st + 1 + mp[a[i]].r - i + 1);
                }
                break;
            }
        }
        */
    }
    cout << ans;
    return 0;
}
