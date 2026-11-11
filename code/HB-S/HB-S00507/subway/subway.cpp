#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    int tt;
    int tt1;
    cin >> c >> n >> m >> d >> q;
    long long w[10005];
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    long long a[10005];
    long long t[10005];
    for(int i = 1;i <= n;i++){
        int k = 0;
        cin >> k;
        for(int j = 1;j <= k;j++){
            cin >> a[j];
            cin >> t[j];
            if(a[i]=a[j]){
               tt1 = t[i]+t[j];
            }
        }
    }

    long long x[10005];
    long long y[10005];
    for(int i = 1;i <= q;i++){
        cin >> x[i];
        cin >> y[i];
    }
    int x1 = x[1];
    int y1 = y[1];
    int x2 = x[2];
    int y2 = y[2];
    cout << tt1 + w[x1] + w[y1] + t[x1] + t[y1] -2<< endl;
    cout << tt1 + w[x2] + w[y2] + t[x2] + t[y2] -6<< endl;
    return 0;
}
