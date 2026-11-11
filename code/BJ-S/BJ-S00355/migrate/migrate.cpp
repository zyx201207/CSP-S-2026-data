#include<bits/stdc++.h>
using namespace std;
int c, T;
int n, d;
int x[2000006];

void solve_A(){
    memset(x, 0, sizeof(x));
    cin >> n >> d;
    for(int i = 1; i <= n; i ++) cin >> x[i];
    int t = x[2] - x[1];
    if(n < 4 || t * 2 > d || t * 3 <= d){
        cout << "0\n";
        return;
    }
    cout << n - 3 << "\n";
}

int touch[11];
int step, cnt[10];
void dfs(int u, int v){
    if(u == v){
        cnt[step] ++;
        //cout << "step:" << step << "\n";
        step --;
        return;
    }
    for(int i = u + 1; i <= touch[u]; i ++){
        if(touch[i] == 0 && i != v){
            step = 0;
            //cout << "No Found!\n";
            return;
        }
        step ++;
        //cout << i << " " << v << "    ";
        dfs(i, v);
    }
}

void solve_hit(){
    memset(x, 0, sizeof(x));
    int ans = 0;
    cin >> n >> d;
    for(int i = 1; i <= n; i ++) cin >> x[i];
    for(int i = 1; i <= n; i ++) touch[i] = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = i + 1; j <= n; j ++){
            if(x[j] - x[i] <= d)
                touch[i] = j;
            else break;
        }
    for(int i = 1; i <= n; i ++)
        for(int j = i + 3; j <= n; j ++){
            if(j <= touch[i]) continue;
            step = 0;
            for(int i = 1; i <= n; i ++) cnt[i] = 0;
            dfs(i, j);
            for(int i = 2; i <= 9; i ++){
                if(cnt[i] != 0 && cnt[i] != 2) break;
                if(cnt[i] == 2){
                    ans ++;
                    break;
                }
            }
            //for(int i = 1; i <= n; i ++) cout << cnt[i] << " ";
            //cout << "\n";
        }
    cout << ans;
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> c >> T;
    if(c == 11 || c == 12){
        while(T--) solve_A();
        return 0;
    }
    if(c <= 3){
        while(T--) solve_hit();
        return 0;
    }
    return 0;
}
