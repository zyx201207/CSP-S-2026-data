#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--){
        int n, d, a[2000005];
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
       if(a[n] - a[1] <= d){
            cout << 0 << endl;
            continue;
        }
        if(c == 11 || c == 12){
            double tms = 1.0 * d / (a[2] - a[1]);
            cout << tms << endl;
            if(tms <= 1) cout << 0 << endl;
            else cout << n - 2 * floor(tms) + 1;
        }
        if(c == 13 || c == 14){
            for(int i =  1; i <= n; i++){
                if(a[i] - a[1] <= d && a[n] - a[i] <= d){
                    if(abs((a[i] - a[1]) - (a[n] - a[i])) == 1) cout << 1;
                    else cout << 0;
                    break;
                }
            }
        }
        else{
            int ans = 0;
            for(int i = 1; i <= n; i++){
                if(a[i] - a[i - 1] > d){
                    n = i - 1;
                    break;
                }
            }
            cout << n << endl;
            for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                    int l=i, r=j, suml[n / d + 5], sumr[n / d + 5], topl = i, topr = j;
                    for(l = i, r = j; l <= r; l++, r--){
                        if((suml[topl] + a[l] - a[l - 1]) > d) suml[++topl] = 0;
                        else sumr[topl]++;
                        if((sumr[topr] + a[r + 1] - a[r]) > d) sumr[++topr] = 0;
                        else sumr[topr]++;
                    }
                    if(abs(sumr[topr] - suml[topl]) == 1) ans++;
                }
            }
            cout << ans;
        }
    }
}
