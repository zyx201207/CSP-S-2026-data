#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e5 + 10;

int c, T;
int n, d;
vector<int> g[N];
int x[N];
bool st[N];
int cnt, minn = 0x3f3f3f3f;

void dfs(int u, int t, int res){
    if (u == t){
        if (res < minn){
            minn = res;
            cnt = 1;
        }
        else cnt ++;
        return;
    }
    for (int i = u + 1; i <= t; i ++)
        if (abs(x[i] - x[u]) <= d && !st[i])
        {
            st[i] = 1;
            dfs(i, t, res + 1);
            st[i] = 0;
        }
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> c >> T;
    while (T -- ){
        cin >> n >> d;
        for (int i = 1; i <= n; i ++ ) cin >> x[i];

        int ans = 0;
        cnt = 0;
        for (int i = 1; i <= n; i ++ ){
            for (int j = i + 1; j <= n; j ++ )
            {
                for (int k = 1; k <= n; k ++ )st[k] = 0;
                cnt = 0;
                minn = 0x3f3f3f3f;
                st[i] = 1;
                dfs(i, j, 0);
                if (cnt == 2) ans ++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
