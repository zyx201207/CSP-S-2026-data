#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    cin >> c >> n >> m >> d >> q;
    int w[10005];
    for(int i = 1;i <= m;i++){cin >> w[i];}
    int a[10005],t[10005];
    for(int i = 1;i <= n;i++){cin >> a[i] >> t[i];}
    int i[10005],k[10005];
    for(int j = 1;j <= q;j++){cin >> k[j];}
    int x[10005],y[10005];
    for(int j = 1;j <= q;j++){cin >> x[j] >> y[j];}

    int num = 0;
    while(1){
        int i = x[q];
        num += w[x[q]] + t[x[q]];
        if(n >= 1){
            num += t[y[q]] + w[y[q]];
            cout << num;
            break;
        }
        if(n == 2){
            for(int j = 1;j <= m;j++){
                for(int h = j;h <= m;h++){
                    if(k[i[j]] == k[i[h]]){
                        num += t[j[q]] + t[h[q]];
                        num += t[y[q]] + w[y[q]];
                        cout << num;
                        break;
                    }
                }
            }
        }

    }

    return 0;
}
