#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t, n, d, a[N], cnt;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
            cnt = 0;
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int f = d / (a[2] - a[1]);
        for(int i = 1; i <= n; i++){
            for(int j = i + f; j < n; j++){
                if(j - i > f && (j - 1) % f != 0) cnt++;
            }
        }
    cout << cnt << endl;
    }
    return 0;
}
