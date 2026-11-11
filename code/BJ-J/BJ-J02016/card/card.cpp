#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
#define N 500005
#define M 300005
using namespace std;

int n,m,a[N],ans[M],app[M];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    memset(app, 0x3f, sizeof app);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        app[a[i]] = i;
    }
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;) {
            if(app[a[j]] != INF && app[a[j]] > j) {
                j = app[a[j]];
            } else {
                ans[a[j]] ++;
                j++;
            }
        }
    }
    for(int i=1;i<=m;i++) {
        cout << ans[i] <<' ';
    }
    return 0;
}
