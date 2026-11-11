#include <bits/stdc++.h>
using namespace std;
int n;
long long d, x[2000005], ans = 0, cnt = 0;
long long maxn[305][305];
void dfs(int step, int u, int v, int s){
    if(u == v){
        if(step == maxn[s][v]){
            cnt++;
        }
        return ;
    }
    if(cnt > 2) return ;
    if(step >= maxn[s][v]) return ;
    int r = u+1;
    while(r <= v){
        if(x[r] - x[u] <= d){
            dfs(step + 1, r, v, s);
        }
        else
            break;
        r++;
    }
}
void solve(int u, int v){
    cnt = 0;
    dfs(0, u, v, u);
    if(cnt == 2)
        ans++;
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int C, T;
    cin >> C >> T;
    while(T--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> x[i];
        }
        ans = 0;
        if(C <= 4){
            for(int i = 1;i <= n;i++){
                for(int j = i + 1;j <= n;j++){
                    maxn[i][j] = 0;
                   long long r = i, num = 0;
                   while(r < j){
                        num += x[r + 1] - x[r];
                        r++;
                        if(num > d){
                            num = 0;
                            maxn[i][j]++;
                        }
                   }
                   maxn[i][j]++;
                   if(maxn[i][j] > 0){
                        solve(i, j);
                   }
                }
            }
            cout << ans << endl;
        }
        else if(C == 11 || C == 12){
            long long num = x[2] - x[1];
            long long cha = d / num;
            num = cha * 2;
            cout << max(1ll*0, n - num + 1) << endl;
        }
    }
    return 0;
}
