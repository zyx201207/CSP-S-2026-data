#include <bits/stdc++.h>

using namespace std;

long long m, ttm;
long long n;
long long ai[514514];
long long delta[514514];

bool cmp(int a, int b){return a > b;}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) cin >> ai[i];
    sort(ai + 1, ai + n + 1);
    long long ans = 0, now = 0, nowp = 1;
    ttm = m;
    for (long long i = 1; i <= n; i++){
        ttm -= (ai[i] - ai[i - 1]) * (i - nowp);
        now++;
        while (ttm < 0){
            now--;
            ttm += ai[i] - ai[nowp++];
        }
        ans = max(ans, now);
    }
    cout << ans;
    return 0;
}
