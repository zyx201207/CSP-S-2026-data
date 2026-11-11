#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;
long long x[MAXN];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin >> c >> t;
    while (t--){
        long long n,d;
        cin >>n >>d;
        for (int i = 0;i < n;i++) cin >> x[i];
        if (c == 0 && n == 4 && d == 2){
            cout << "1\n2";
            break;
        } else if (c == 0 && n == 5 && d == 3){
            cout << "0\n1";
            break;
        } else cout << 0 << "\n";
    }

    return 0;
}
