#include <bits/stdc++.h>
#define int long long
using namespace std;
int w[500010];
vector<int>g[500010];

signed main(){
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c , n , m , d , q , x , y , ans = 0;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
        ans += w[i];
    }
    int k;
    for(int i = 1;i <= n;i++){    
        cin >> k;
        for(int j = 1;j <= k;j++){
            cin >> x >> y;
            ans += y;
        }

    }
    cout << ans;
    return 0;
}
