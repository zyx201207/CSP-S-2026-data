#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    int c,n,m,d,q,a[1005][1005],w[10005],t[1005][1005]={-114514},k[10005];
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++)cin >> w[i];
    for(int i = 1;i <= n;i ++){
            cin >> k[i]
        for(int j = 1;j <= k[i];j ++){
            cin >> a[i][j] >> t[i][j];
        }
        for(int i = 1;i <= q;i ++){
            int x,y;
            cin >> x >> y;
            
        }
    }
    return 0;
}
