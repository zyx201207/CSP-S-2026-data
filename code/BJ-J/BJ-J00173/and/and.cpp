#include <bits/stdc++.h>
#define N 300010
#define int long long
using namespace std;
int n, a[N], m, answer, t;
bool vis[N];
void dfs(int step, int total){
    t++;
    if(t >= 1e7){
        cout << answer << endl;
        exit(0);
    }
    if(total > m){
        return ;
    }
    if(step > n){
        if(total == m){
            int sum = 0;
            for(int i = 1; i <= n; i++){
                t++;
                if(vis[i]){
                    sum = a[i];
                    break;
                }
            }
            for(int i = 1; i <= n; i++){
                if(vis[i]){
                    sum &= a[i];
                }
            }
            answer = max(answer, sum);
        }
        return ;
    }
    vis[step] = true;
    dfs(step + 1, total + 1);
    vis[step] = false;
    dfs(step + 1, total);
}
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int maxn = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    if(m == 1){
        cout << maxn << endl;
        return 0;
    }
    if(m == n){
        int sum = a[1];
        for(int i = 2; i <= n; i++){
            sum &= a[i];
        }
        cout << sum << endl;
        return 0;
    }
    if(m == 2){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j){
                    continue;
                }
                sum = max(sum, (a[i] & a[j]));
            }
        }
        cout << sum << endl;
        return 0;
    }
    dfs(1, 0);
    cout << answer << endl;
    return 0;
}
