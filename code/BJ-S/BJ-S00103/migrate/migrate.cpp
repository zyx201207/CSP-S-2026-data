#include<bits/stdc++.h>
using namespace std;
int main () {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    int nxt[200001];
    int sp[200001];
    int sn[200001];
    int jp[200001];
    int pre[200001];
    int p[200001];
    int jn[200001];
    int v;
    cin >> c >> t;
    for(int i = 1;i <= t;i++) {
        int n,d;
        cin >> n >> d;
        int x[n+1];
        for (int i = 1;i <= n;i++){
            cin  >> x[i];
        }
            cin >> n >> d;
            for (int i = 1;i <= n;i++) {
                nxt[i]=pre[i]=p[i]=jn[i]=sn[i]=jp[i]=sp[i];
        }
        for (int i = 1;i <= n;i++) {
            if (nxt[pre[i]]==1) {
                v = jp[i];
            }
            else {
                v = sp[i];
            }
        }
        for (int i = 1;i <= n;i++) {
            sn[i]=jp[i]+sp[n];
        }
        int ans = 0;
        for (int i = 1;i <= n;i++) {
            if (pre[i]!=pre[i+1]) {

            }
        }
    while (t--) {
        main ();
    }
    cout << pre[i];
}
    return 0;
}