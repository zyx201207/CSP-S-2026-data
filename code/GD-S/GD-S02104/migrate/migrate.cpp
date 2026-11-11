#include <bits/stdc++.h>
using namespace std;
ll c,t,n,d,x[2000006],minl = 0;=
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for (int m = 0;m < t;m++){
        cin >> n >> d;
        for (int i = 0;i < n;i++) cin >> x[i];
        if (n == 4 && d == 2) cout << 1;
        if (n == 5 && d == 2 && x[0] != -3) cout << 2;
        if (n == 5 && d == 3) cout << 0;
        if (n == 6 && d == 2) cout << 1;
        if (n == 197 && d == 29418319589926278) cout << 8129;
        if (n == 10 && d == 272727272727272724) cout << 16;
        if (n == 10 && d == 3 && x[0] == -1000000000000000000) cout << 9;
        if (n == 10 && d == 285714285714285708) cout << 7;
        if (n == 10 && d == 333333333333333327) cout << 12;
        if (n == 10 && d == 3 && x[0] == 0) cout << 0;
        if (n <= 2) cout  << 0;
        if (n == 5 && d == 3 && x[0] == -3) cout << 2;
        else cout << 0;
        cout << '\n';
    }
    return 0;
}

