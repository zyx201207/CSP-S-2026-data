#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

ll x[305], f[305][305], num[305][305];

void solve(){
    ll n, d;
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
        cin >> x[i];
    memset(f, 0x20, sizeof(f));
    memset(num, 0, sizeof(num));
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(x[j] - x[i] <= d)
                f[i][j] = 1, f[i][j] = 1;
        }
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(f[i][k] + f[k][j] == f[i][j])
                    num[i][j]++;
                else if(f[i][k] + f[k][j] < f[i][j])
                    f[i][j] = f[i][k] + f[k][j], num[i][j] = 1;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ans += (num[i][j] == 2);
            //cout << num[i][j] << " \n"[j == n];
        }
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    //auto t = clock();
    int c, T = 1;
    cin >> c >> T;
    for(int i = 1; i <= T; i++)
        solve();//cout << "0\n";
    //cout << clock() - t;
}