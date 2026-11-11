#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[505],k[505],a[255],t[255],x[50005],y[50005];
long long sum;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= 2 * k[i];k++){
            cin >> a[j] >> t[j];
        }
    }
    for(int i = 1;i <= q;i++){
        cin >> x[i] >> y[i];
    }

    for(int i = 1;i <= q;i++){
        sum += w[x[i] + w[y[i];
        for(int j = 1;j <= n;j++){
            
        }
    }
    return 0;
}
