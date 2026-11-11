#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int c, t, n, d, Ans, tttt;
int a[N], s[N];
void dfs(int lll, int rrr, int summm, int cnt){
    if(cnt == summm){
        if(lll == rrr){
            tttt ++;
        }
        return;
    }
    if(s[lll] == 0) return;
    for(int i = 1; i <= s[lll]; i ++){
        dfs(lll + i, rrr, summm, cnt + 1);
    }
    return;
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    for(int i = 1; i <= t; i ++){
        cin >> n >> d;
        Ans = 0;
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i ++){
            int tttt = a[i] + d;
            int l = i, r = n, ans = 0;
            while(l <= r){
                int mid = (l + r) / 2;
                if(tttt > a[mid]){
                    ans = mid;
                    l = mid + 1;
                }
                else if(tttt == a[mid]){
                    ans = mid;
                    break;
                }
                else{
                    r = mid - 1;
                }
            } 
            s[i] = ans - i;
        }
        int p = a[2] - a[1], op = 0;
        for(int i = 3; i <= n; i ++){
            if(a[i] - a[i - 1] != p) op = 1;
        }
        if(!op){
            for(int i = 1; i <= n; i ++){
                if(i + 2 * s[1] - 1 > n || s[1] == 1) continue;
                Ans ++;
            }
            cout << Ans << '\n';
        }else{
            for(int i = 1; i <= n; i ++){
                for(int j = i + 1; j <= n; j ++){
                    int ll = i, rr = j, sum = 0, op = 1;
                    while(ll < rr){
                        if(s[ll] == 0){
                            op = 0;
                            break;
                        }
                        ll += s[ll];
                        sum ++;
                    }
                    if(op == 1){
                        tttt = 0;
                        dfs(i, j, sum, 0);
                        if(tttt == 2) Ans ++;
                    }
                }
            }
            cout << Ans << '\n';
        }
    }
    return 0;
}