#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in", r, stdin);
    freopen("hub.out", r, stdout);
    int c, t;
    int n[t + 5], k[t + 5];
    int u[t + 5], v[t + 5];
    for(int i = 1;i <= t;++i){
        cin >> n[i] >> k[i];
        cin >> u[i] >> v[i];
    }
    int c = 0;
    int minn = 1e9;
    for(int i = 1;i <= t;i++){
        c = n[i] + u[i] - 2 * v[i] + k[2 * i] - n[i]/v[i] * u[i] + 3 * v[i] - k[i] + v[i] * u[i] - n[i] * u[i] * k[i]/v[i] * (n[i] + k[i]);
        cout << c << endl;
    }
    return 0;
}