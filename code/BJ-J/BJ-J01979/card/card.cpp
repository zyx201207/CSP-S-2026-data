# include <bits/stdc++.h>
using namespace std;
# define int long long
const int N = 5e5+5, M = 3e5+5;
int n,m,a[N],b[M],c[N],d[N],f[N],g[N],to[N],ans[M];


signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=n;i>=1;i--){
        if (b[a[i]] == 0){
            c[i] = n+1;
        }
        else{
            c[i] = b[a[i]];
        }
        b[a[i]] = i;
    }


    int mn = 1e9;
    for (int i=1;i<=n;i++){
        d[i]++;
        if (c[i] != n+1){
            d[c[i]] += d[i];
            d[i] = 0;
        }
        else{
            mn = min(mn, i);
        }
    }

    int cnt = 0, tot = 0;
    for (int i=mn;i<=n;i++){
        if (d[i] != 0){
                f[i] += d[i];
        }
        else{
            f[i] -= tot;
            f[c[i]] += tot;

            g[c[i]] += tot;
            tot = 0;

        }
        if (g[i]) tot += g[i];
    }

    for (int i=1;i<=n;i++){
        to[i] = to[i-1] + f[i];
    }
    for (int i=1;i<=n;i++){
        if (d[i]) ans[a[i]] += to[i];
    }
    for (int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
