#include <bits/stdc++.h>
using namespace std;
int n, m, r = 1, a[500005], b[500005], d[300005], e[300005], c[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            if (c[a[j]] == 0){
                b[r] = a[j];
                d[a[j]] = r;
                r++;
                c[a[j]] = 1;
            }
            else{
                r = d[a[j]] + 1;
                for (int k = 1; k <= m; k++){
                    if (d[k] > d[a[j]]){
                        c[k] = 0;
                        d[k] = 0;
                    }
                }
            }
        }
        for (int j = 1; j <= m; j++){
            e[j] = e[j] + c[j];
        }
        r = 1;
        for (int j = 1; j <= n; j++) b[j] = 0;
        for (int j = 1; j <= m; j++){
            c[j] = 0;
            d[j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) cout << e[i] << " ";
    return 0;
}
