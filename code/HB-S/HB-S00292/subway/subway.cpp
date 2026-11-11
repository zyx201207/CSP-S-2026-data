#include<bits/stdc++.h>
using namespace std;
int e,n,m,d,q,x,k,ans,y,a[500005],b[500005][500005],cnt[500005][500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> e >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> k;
        for(int j=1;j<=k;j++){
            cin >> b[i][j] >> cnt[i][j];
        }
    }
    for(int r=0;r<q;r++){
        ans = 0;
        cin >> x >> y;
        ans += a[x] + a[y];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                if(b[i][j]==x || b[i][j]==y) ans+=cnt[i][j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
