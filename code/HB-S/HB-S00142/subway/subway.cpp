#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,p,k[10005],w[100005],a[1005][1005],t[1005][1005];
int r1[10005],r2[10005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> p;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            cin >> a[i][j] >> t[i][j];
        }
    }
    for(int i=1;i<=p;i++){
        cin >> r1[i] >> r2[i];
    }
    return 0;
}
