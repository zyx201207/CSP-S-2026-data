#include<bits/stdc++.h>
using namespace std;
int xr, yr;
int c, n, m, d, q;
int k;
int cnt = 0;
vector<int> ax, ay, s;
int w[500010];
void solve(int x, int y){
    int ans = 0;
    ans += w[x];
    while(x <= y){
        for(int i = 0; i <= cnt; i++){
            if(ax[i] == x){
                ans += ay[1];
            }
        }
        x++;
    }
    ans += w[y];
    cout << ans << '\n';
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> k;
        cnt+= k;
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            ax.push_back(x);
            ay.push_back(y);
        }
    }

    cin >> xr >> yr;
    solve(xr, yr);
    cin >> xr >> yr;
    solve(xr, yr);
    return 0;
}
