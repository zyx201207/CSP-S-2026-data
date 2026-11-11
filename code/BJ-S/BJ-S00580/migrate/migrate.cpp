#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005],k;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while (t--){
        cin >> n >> d;
        for (int i=1; i<=n; i++) cin >> x[i];
        if (n<=3||d<=abs(x[2]-x[1])||d>=abs(x[n]-x[1])){
            cout << 0 << endl;
            continue;
        }
        k = d/abs(x[2]-x[1]);
        if (k%2==1) cout << n-k-2 << endl;
        else cout << n-k-1 << endl;
    }
    return 0;
}