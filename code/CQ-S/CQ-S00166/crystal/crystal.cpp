#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
typedef pair < int, int > PII;
const int N = 5e5 + 5;
long long s[N];
long long n, m;
bool check(long long x)
{
    long long head = x, cur = 0;
    for(int i = 1; i <= x; i++)cur += abs(s[i] - s[head]);
    for(int i = 1; i + x - 1 <= n; i++)
    {
        if(cur <= m)return 1;
        cur += x * abs(s[head + 1] - s[head]);
        cur -= abs(s[head] - s[i]);
        head++;
    }
    return 0;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> s[i];
    sort(s + 1, s + n + 1);
    int l = 1, r = n, ans = 1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(check(mid))
        {
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    cout << ans;
    return 0;
}