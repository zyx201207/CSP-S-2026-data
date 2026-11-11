#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,t;
    cin >> c >> t;
    int n,k;
    int u[10005],v[10005];
    for(int j = 1;j <= t;j++){
        cin >> n >> k;
        for(int q = 1;q <= n-1;q++){
            cin >> u[q] >> v[q];
        }
    }

    return 0;
}
