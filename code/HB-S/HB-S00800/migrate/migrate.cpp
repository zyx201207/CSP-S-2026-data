#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int x[N];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t --){
        int n, d, p;
        cin >> n >> d;
        for(int i = 1; i <= n; i ++){
            cin >> x[i];
            p = x[i] - x[i - 1];
        }
        if(p > 2 * d){
            cout << 0 << endl;
        }
        else{
            cout << n - 2 << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
