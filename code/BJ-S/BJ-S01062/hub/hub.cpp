#include <bits/stdc++.h>
using namespace std;
const int N = 4e3 + 5;
int n , m , k , dep[N] , mx[N] , f[N];
vector <int> e[N];
void dfs(int x , int fa){
    dep[x] = dep[fa] + 1;
    mx[x] = dep[x];
    for (int y : e[x]){
        if (y != fa){
            dfs(y , x);
            mx[x] = max(mx[x] , mx[y]);
        }
    }
}
void solve(int x , int fa){
    f[x] = 1;
    for (int y : e[x]){
        if (y == fa) continue;
        solve(y , x);
        if (mx[y] - dep[x] > k) f[x] += f[y];
    }
}
int lim , sum;
void fun(int x , int fa){
    int t = 0;
    bool flag = 0;
    for (int y : e[x]){
        if (y == fa) continue;
        if (mx[y] - dep[x] >= k){
            if (t) flag = 1;
            else t = y;
        }
        else lim = min(lim , k - (mx[y] - dep[x]) + dep[x]);
    }
    if (!t || dep[x] >= lim) flag = 1;
    if (flag) sum += f[x];
    else fun(t , x);
}
bool check(int kk){
    k = kk;
    for (int rt = 1;rt <= n;rt++){
        dfs(rt , 0);
        solve(rt , 0);
        if (f[rt] <= m) return 1; 
        if (!kk) continue;
        int x = 0 , y = 0 , z = 0;
        bool flag = 1;
        for (int i : e[rt]){
            if (mx[i] - 1 >= k){
                if (!x) x = i;
                else if (!y) y = i;
                else flag = 0;
            }
            else z = max(z , mx[i] - 1);
        }
        if (flag && x && y){
            sum = 0 , lim = k - z + 1;
            fun(x , rt);
            lim = n;
            fun(y , rt);
            if (sum <= m) return 1;
        }
    }
    return 0;
}
int main(){
    freopen("hub.in" , "r" , stdin);
    freopen("hub.out" , "w" , stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int caseid , cases;
    cin >> caseid >> cases;
    while (cases--){
        cin >> n >> m;
        int x , y;
        for (int i = 1;i < n;i++){
            cin >> x >> y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        int l = 0 , r = n , mid , ans;
        while (l <= r){
            mid = l + r >> 1;
            if (check(mid)) ans = mid , r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << '\n';
        for (int i = 1;i <= n;i++){
            e[i].clear();
        }
    }
    return 0;
}