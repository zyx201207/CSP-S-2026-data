#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define int long long
using namespace std;

const int N = 305;
int c , t , a[2000005] , cnt , minn = 1e18 , vis[N];
vector<int> v[N];
void dfs(int x , int y , int r)
{
    if(x == y)
    {
        if(minn > r) {cnt = 1;minn = r;}
        else if(minn == r) cnt++;
        return;
    }
    for(auto p : v[x])
        if(!vis[p])
        {
            vis[p] = 1;
            dfs(p , y , r + 1);
            vis[p] = 0;
        }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    cin >> c >> t;
    if(c == 11 || c == 12)
    {
        while(t--)
        {
            int n , d;cin >> n >> d;
            for(int i = 1; i <= n; i++) cin >> a[i];
            int cnd = a[2] - a[1];
            if(n == 1) {cout << 0 << "\n";continue;}
            int maxn = d / cnd;
            if(maxn == 0 || maxn == 1 || ((maxn * 2 - 1) >= n)) {cout << 0 << "\n";continue;}
            else
            {
                int len = maxn * 2 - 1;
                cout << n - len << "\n";
            }
        }
    }
    else if(c == 13 || c == 14)
    {
        while(t--)
        {
            int n , d;cin >> n >> d;
            for(int i = 1; i <= n; i++) cin >> a[i];
            if(n == 1) {cout << 0 << "\n";continue;}
            int ans = n * (n - 1);
            for(int i = 1; i <= n; i++)
            {
                int p = (upper_bound(a + 1 , a + n + 1 , a[i] + d) - a);
                ans -= n - p + 1;
            }
            cout << ans << "\n";
        }
    }
    else
    {
        while(t--)
        {
            int n , d , ans = 0;cin >> n >> d;
            for(int i = 1; i <= n; i++) {cin >> a[i];v[i].clear();}
            if(n == 1) {cout << 0 << "\n";continue;}
            for(int i = 1; i <= n; i++)
                for(int j = i + 1; j <= n; j++)
                    if(a[j] - a[i] <= d) {v[i].push_back(j);v[j].push_back(i);}
            for(int i = 1; i <= n; i++)
                for(int j = i + 1; j <= n; j++)
                {
                    cnt = 0;
                    minn = 1e18;
                    memset(vis , 0 , sizeof vis);
                    dfs(i , j , 0);
                    if(cnt == 2) {ans++;}
                }
            cout << ans << endl;
        }
    }
    return 0;
}
/*
10 1999999999999999970
-899999999999999986 -699999999999999989 -499999999999999992 -299999999999999995 -99999999999999998 99999999999999999 299999999999999996 499999999999999993 699999999999999990 899999999999999987
*/
