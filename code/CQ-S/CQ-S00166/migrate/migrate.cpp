#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
typedef pair < int, int > PII;
const int N = 2e6 + 5;
long long s[N];
int n;
long long d;
long long bfs(int st)
{
    pair < long long, long long > ygg[n];
    for(int i = 1; i <= n; i++)ygg[i].fir = LLONG_MAX;
    queue < PII > q;
    q.push({st, 0});
    while(!q.empty())
    {
        int pos = q.front().fir, stp = q.front().sec;
        q.pop();
        if(ygg[pos].fir > stp)ygg[pos] = {stp, 1};
        else if(ygg[pos].fir == stp)ygg[pos].sec++;
        for(int i = pos + 1; i <= n && s[i] - s[pos] <= d; i++)q.push({i, stp + 1});
    }
    int cnt = 0;
    for(int i = st + 1; i <= n; i++)if(ygg[i].sec == 2)cnt++;
    return cnt;
}
void solve()
{
    cin >> n >> d;
    for(int i = 1; i <= n; i++)cin >> s[i];
    long long ans = 0;
    for(int i = 1; i <= n; i++)ans += bfs(i);
    cout << ans << "\n";
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C, T;
    cin >> C >> T;
    while(T--)solve();
    return 0;
}
