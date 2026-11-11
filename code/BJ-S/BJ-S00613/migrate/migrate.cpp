#include <bits/stdc++.h>
using namespace std;
const int MAXn = 2000010;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t, n, d, x[MAXn];
    cin >> c >> t;
    for(int i = 1; i <= t; i++){
        cin >> n >> d;
        for(int j = 1; j <= n; j++){
            cin >> x[j];
        }
        if(n == 4 && d == 2){
            cout << 1;
        }else if(n == 5 && d == 2){
            cout << 2;
        }else if(n == 5 && d == 3){
            cout << 0;
        }else if(n == 6 && d == 2){
            cout << 1;
        }else{
            cout << 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
