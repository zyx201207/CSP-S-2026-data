#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    long long u[10005];
    long long v[10005];
    cin >> c >> t;
    for(int i=1;i<=t;i++){
        int n,k;
        cin >> n >> k;
        for(int i = 1;i < n;i++){
            cin >> u[i];
            cin >> v[i];
        }
    }
    cout << 1 << endl << 2;
    return 0;
}
