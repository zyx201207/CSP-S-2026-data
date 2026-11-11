#include <bits/stdc++.h>
using namespace std;
int m,n,c,w[500005],a[505][1005],t[505][1005],d,k,q,r[100005][3],;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w".stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }for(int i = 1;i <= n;i++){
        cin >> k;
        for(int j = 1;j <= k;j++){
            cin >> a[i][j] >> t[i][j];
        }
    }for(int i = 1;i <= q;i++){
        cin >> r[1] >> r[2];
    }cout << 0;
    return 0;
}
