#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
        cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin >> c >> t;
    while(t--){
        int n,d;
        cin >> n >> d;
        long long a[1000010];
        for(long long i = 1;i <= n; i++){
            cin >> a[i];
        }
        long long ans = 0;
        for(long long i = 1;i <= n; i++){
            for(long long j = i;j <= n; j++){
                if(a[j] - a[i] == n + n - 1 && j - i >= 2){
                    ans++;
                }
            }
        }
        cout << ans;
    }
    return 0;
}
