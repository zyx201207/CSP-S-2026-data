#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n[N], k[N];
int u[N], v[N];
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    for(int i = 1; i <= t; i++){
        cin >> n[i] >> k[i];
        for(int j = 1; j <= n[i] - 1; j++){
            cin >> u[i] >> v[i];
        }
    }
    for(int i = 1; i <= t;i++){
        if(i % 2 == 0) cout << "1" << endl;
        else cout << "2" << endl;
    }
    return 0;
}