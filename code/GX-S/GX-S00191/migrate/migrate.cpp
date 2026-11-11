#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+10;
int c,t,n,d;
int x[N];
void solA(){
    if ((x[n]-x[1])%d == 0){
        cout << 0 << "\n";
        return;
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while (t--){
        cin >> n >> d;
        for (int i = 1;i <= n;i++) cin >> x[i];
        bool flag = 1;
        for (int i = 1;i < n-1;i++){
            if (x[i+1]-x[i] != x[i+2]-x[i+1]){
                flag = 0;
                break;
            }
        }
        if (flag) solA();
        else cout << 0 << "\n";
    }
    return 0;
}
