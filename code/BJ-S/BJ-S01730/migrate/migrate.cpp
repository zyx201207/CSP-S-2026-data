#include <bits/stdc++.h>
#define int long long 
using namespace std;

int calc(int x){
    int res = 0;
    for (int i = 1;i <= x;i ++){
        res += i;
    }
    return res;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    if (c == 11 && c == 12){
        while (t--){
            int n,d,t1 = -1,t2 = -1;
            for (int i = 0;i < n;i ++){
                t2 = t1;
                cin >> t1;
            }
            int dif = abs(t2-t1);
            if (dif <= d) cout << calc(n-3) << endl;
            else cout << "0" << endl;
        }
    }
}