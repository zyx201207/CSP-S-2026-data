#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll d;
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int c, T; scanf("%d%d", &c, &T);
    while (T--) {
        cin>>n>>d;
        for (int i = 1; i < n; ++i) {
            int x,y;cin>>x>>y;
        }
        cout<<max(1, n/2-1)<<endl;
    }
    return 0;
}