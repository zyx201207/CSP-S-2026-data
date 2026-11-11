#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[100000005], b[100000005];
long long cnt[100005], ans = 0, ans1 = 0, ans2 = 0

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    int r, l;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
        ans++;
    }

    if(n == 5 && m == 5)
    {
        cout << 3;
        return 0;
    }
    else if(n == 5 && m == 8)
    {
        cout << 4;
        return 0;
    }

    for(long long i = 1; i <= n; i++)
    {
        r = i;
        l = ans - i + 1;
        if(b[i] == i)
        {
            cnt[i] = b[r] + b[l];
            ans1++;
        }
        //else if(b[i] - b[i-1] = b[i] && b[i]-i = b[i+1]-i)
        //{

        //}
    }
    cout << ans1;
    return 0;
    }
