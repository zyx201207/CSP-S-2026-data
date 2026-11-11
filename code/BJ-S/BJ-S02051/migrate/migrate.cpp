#include<bits/stdc++.h>
using namespace std;
int c, t, n, d, a[2000010];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int ans = 0;
        for(int j = 1; j < n; j++){
            for(int k = j+3; k <= n; k++){
                int cnt = 0;
                if(a[k]-a[j] <= d){
                    continue;
                }
                for(int i = j+1; i < k; i++){
                    if(a[i]-a[j] <= d && a[k]-a[i] <= d){
                        cnt++;
                    }
                }
                if(cnt == 2){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
