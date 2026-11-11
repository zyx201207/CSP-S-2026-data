#include<iostream>
using namespace std;
long long n, a[200010], ans;
char c[200010];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> c[i];
        a[i] += a[i - 1];
    }
    long long left = 0, right = a[n], l = 1, r = n;
    while(l <= r)
    {
        long long minn = min(a[l] - left, right - a[r]);
        if(c[l] != c[r + 1])
        {
            ans += minn;
        }
        if(minn == a[l] - left)
        {
            ++l;
        }
        if(minn == right - a[r])
        {
            --r;
        }
        left += minn;
        right -= minn;
    }
    cout << ans;
    return 0;
}
