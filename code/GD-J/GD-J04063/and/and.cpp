#include <bits/stdc++.h>
using namespace std;

long long a[200010];

bool cmp(long long x,long long y)
{
    return x > y;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    long long n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }

    sort(a + 1,a + n + 1,cmp);

    long long ans1 = a[1];
    for(int i = 2;i <= m;i ++)
    {
        ans1 = ans1 & a[i];
    }

    long long ans2 = 0;
    for(int i = 1;i <= n;i ++)
    {
        bool is_ = 1;
        for(int j = i + 1;j <= i + m - 1;j ++)
        {
            if(a[i] != a[j])
            {
                is_ = 0;
                break;
            }
        }
        if(is_)
        {
            ans2 = a[i];
            break;
        }
    }
    ans1 = max(ans1,ans2);
    cout << ans1;

    return 0;
}
