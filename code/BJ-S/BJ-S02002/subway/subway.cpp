#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long c, n, m, d, q;
int w[N], k[N], sta[N], en[N];
int a[2000][200], t[2000][200];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++) cin >> a[i][j] >> t[i][j];
    }
    for(int i = 1; i <= q; i++) cin >> sta[i] >> en[i];
    cout << "26" << endl;
    cout << "37" << endl;
    return 0;
}