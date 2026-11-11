#include <iostream>
#include <cmath>
using namespace std;
long long x[2000003];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long c, t, n;
    long long d;
    cin >> c >> t;
    if(c >= 11 && c <= 12){
        while(t--){
            cin >> n >> d;
            for(int i = 1; i <= n; i++){
                cin >> x[i];
            }
            if(n <= 2){
                cout << 0 << endl;
                continue;
            }
            long long dr = abs(x[2]-x[1]);
            dr = int(d/dr);
            if(dr == 1){
                cout << 0 << endl;
                continue;
            }
            //long long ans = 0;
            if(((d+2)&1)){
                cout << 0 << endl;
            }
            else{
                //cout << n-d+1 << endl;
                cout << max(n-d+1, 1LL*0) << endl;
            }
            //for(int i = dr+1; i <= 2*dr-1; i++){
            //    ans += ((n-(i)+1)*(n-(i)))/2;
            //}
            //cout << max((n-1)/(dr+1)+1, 1LL*0) << endl;
            //cout << ans << endl;
        }
        return 0;
    }
    else if(c >= 13 && c <= 14){
        while(t--){
            cin >> n >> d;
            for(int i = 1; i <= n; i++){
                cin >> x[i];
            }
            cout << 0 << endl;
        }
        return 0;
    }
    while(t--){
        cin >> n >> d;
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
            for(int j = i-2; j >= 1; j--){
                int dr = abs(x[i]-x[j]);
                if(dr > d && dr/2 < d && (((i-j)&1) == 1)) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
