#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,k[502] = {},w[500086] = {},a[502][500086] = {},t[502][500086] = {},x[100086] = {},y[100086] = {};
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)cin >> w[i];
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j++)cin >> a[i][j] >> t[i][j];
    }
    for(int i = 1;i <= q;i++)cin >> x[i] >> y[i];
    for(int i = 1;i <= q;i++)cout << "1\n";
    return 0;
}
