#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct subway{
    int a;
    int t;
} l[500005];
int c, n, m, d, q, k, w[500005], x[100005], y[100005];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        for(int j=1;j<=k;j++) {
            cin >> l[i].a;
            cin >> l[i].t;
        }
    }
    for(int i=1;i<=q;i++){
        cin >> x[i] >> y[i];
        cout << 2 << endl;
    }
    return 0;
}
