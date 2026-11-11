#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1010],k[510],a[510][1010],t[510][1010],x,y,p[1010][1010],vis[510];
long long ans;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++) cin >> w[i];
    for(int i = 1;i <= n;i++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j++){
            cin >> a[i][j] >> t[i][j];
        }
        for(int j = 1;j < k[i];j++){
            p[a[i][j+1]][a[i][j]] = i;
            p[a[i][j]][a[i][j+1]] = i;
        }
    }
    for(int i = 1;i <= q;i++){
        cin >> x >> y;
        cout << w[x] + t[1][x] + t[1][y] + w[y] <<  endl;
    }
    return 0;
}
