#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
typedef long long ll;
const int NR = 6e5 + 5;
const int MR = 5005;

int idt;
int n, d;
int a[NR];

int dis[MR][MR];
int dp[MR][MR];
int hqy[NR], pos = 0;
void solve()
{
    cin >> n >> d;
    pos = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) dis[i][j] = 0, dp[i][j] = 0;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i == 1 || a[i] - a[i-1] > d) hqy[++pos] = i;
       // cout << a[i] - a[i-1] << " ";
    }
//cout << endl;
    if(n == 1 || n > 5000){cout << 0 << endl; return ;}
    for(int s = 1; s < n; s++)
    {
        deque<int> q;
        q.push_back(s);
        for(int i = s+1; i <= n; i++)
        {
            while(!q.empty() && a[q.front()] < a[i]-d) q.pop_front();
            dis[s][i] = dis[s][q.front()] + 1;
            while(!q.empty() && dis[s][q.back()] > dis[s][i]) q.pop_back();
            q.push_back(i);
        }
    }
/*
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            printf("dis(%d, %d) = %d\n", i, j, dis[i][j]);
*/
    for(int i = 1; i <= n; i++)
        dp[i][i+1] = 1;

    long long ans = 0;
    hqy[pos+1] = n+1;
    for(int t = 1; t <= pos; t++)
    {
        int L = hqy[t], R = hqy[t+1]-1;
        for(int l = 3; l <= R; l++)
            for(int j = L-1 + l; j <= R; j++)  // 求dp[i][j]
            {
                int i = j-l+1;
                if(a[j] - a[i] <= d) {dp[i][j] = 1; continue;}
                for(int k = i; k <= j; k++)
                    if(dis[i][k] + dis[k][j] == dis[i][j])
                        dp[i][j] += dp[i][k] * dp[k][j];
                if(dp[i][j] > 2) dp[i][j] = 3;
                ans += (dp[i][j] == 2);
            }
    }
//cout << "\t\t\t";
    cout <<ans << endl;
/*
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
    cout << endl;
*/
}

void solve2()
{
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int x = a[2] - a[1];
    if(d < 2*x || n == 1) {cout << 0 << endl; return ;}
    int l = (d / x) + (d/x)-1 + 1;
    cout << n - l + 1 << endl;
}

signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int _;
    cin >> idt >> _;
    if(idt == 11 || idt == 12) {while(_--) solve2();}
    else {while(_--) solve();}
    return 0;
}
