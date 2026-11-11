#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
long long n, m, a[500005], s[500005] = {}, ans = 1;

long long find(long long l, long long r)
{
    if((r - l) < 1)
    {
        return l;
    }
    if((r - l) == 1)
    {
        for (long long j = n; j >= r; j --)
        {
            if(s[j] - s[j - r] + m >= a[j] * r)
            {
                ans = max(ans, r);
                return r;
            }
        }
        return l;
    }
    long long mid = (r + l) / 2;
    for (long long j = n; j >= mid; j --)
    {
        if(s[j] - s[j - mid] + m >= a[j] * mid)
        {
            ans = max(ans, mid);
            return find(mid, r);
        }
    }
    return find(l, mid - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (long long i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    s[0] = 0;
    for (long long i = 1; i <= n; i ++)
    {
        s[i] = s[i - 1] + a[i];
    }
    ans = find(1, n);
    cout << ans;
	return 0;
}
