#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 500002;

ll m;
int n;
int ans;
ll a[MAXN];
ll sum[MAXN];

bool Check(int i,int l)
{
    return (i - l) * a[i] - (sum[i - 1] - sum[l - 1]) <= m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++)
        sum[i] = sum[i - 1] + a[i];
    for(int i = 1;i <= n;i++)
    {
        int p = i;
        if(i == 1)
        {
            ans = 1;
            continue;
        }
        if(Check(i,1))
        {
            ans = max(ans,i);
            continue;
        }
        if(!Check(i - 1,i))
            continue;

        for(int k = 20;k >= 0;k--)
            if(p - (1 << k) >= 1 && Check(i,p - (1 << k)))
                p -= (1 << k);
        ans = max(ans,i - p + 1);
    }

    cout << ans << '\n';
    return 0;
}