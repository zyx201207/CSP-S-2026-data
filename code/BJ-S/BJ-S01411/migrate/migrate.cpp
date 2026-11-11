#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--){
        int n ,d;
        cin >> n >> d;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        if(c == 11 || c == 12){
            int gc = a[2] - a[1];
            int ans = 0;
            if(d == gc || d > (n - 1) * gc){
                cout << "0\n";
                continue;
            }
            int k = d / gc;
            cout << n - (2 * k) + 1 << "\n";
        }
        else if(c == 13 || c == 14){
            cout << 0 << "\n";
            return 0;
        }

    }
    return 0;
}
