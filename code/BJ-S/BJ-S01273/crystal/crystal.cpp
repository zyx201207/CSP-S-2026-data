#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m, a[500010], ans = 1;
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    deque<int>q;
    int t = 0;
    q.push_front(a[1]);
    for(int i = 2; i <= n; i++)
    {
        t += q.size() * (a[i] - q.front());
        q.push_front(a[i]);
        while(t > m)
        {
            t -= q.front() - q.back();
            q.pop_back();
        }
        int a = q.size();
        ans = max(ans, a);
    }
    cout << ans << endl;
    return 0;
}