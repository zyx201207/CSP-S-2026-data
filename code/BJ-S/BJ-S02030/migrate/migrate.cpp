#include <bits/stdc++.h>
using namespace std;
long long f[2005][2005], a[2005];
int  g[2005][2005];
int main(){
     freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--){
        int n, cnt=0;
        long long d;
        memset(f, 0x3f, sizeof(f));
        memset(g, 0, sizeof(g));
        cin >> n >> d;
        for (int i=1; i<=n; ++i){
            cin >> a[i];
        }
        if (c==11 || c==12){
            d/=(a[2]-a[1]);
            if (d<=0)cout << 0 << '\n';
            else
            cout << max(n-2*(int)d+1, 0) << '\n';
            continue;
        }
        for (int i=1; i<=n; ++i){
            for (int j=i+1; j<=n; ++j){
                if (a[j]-a[i]<=d){
                    f[i][j]=1;
                    g[i][j]=1;
                }else break;
            }
        }
        for (int k=1; k<=n; ++k){
            for (int i=1; i<k; ++i){
                for (int j=max(k+1, i+1); j<=n; ++j){
                    if (f[i][j]>f[i][k]+f[k][j]){
                        f[i][j]=f[i][k]+f[k][j];
                        g[i][j]=g[i][k]*g[k][j];
                    }
                    else if (f[i][j]==f[i][k]+f[k][j]){
                        g[i][j]+=g[i][k]*g[k][j];
                    }
                    if (g[i][j]>3) g[i][j]=3;
                }
            }
        }
        for (int i=1; i<=n; ++i){
            for (int j=i+1; j<=n; ++j){
                if (g[i][j]==2) ++cnt;
            }
        }
        cout << cnt <<'\n';
    }
    return 0;
}