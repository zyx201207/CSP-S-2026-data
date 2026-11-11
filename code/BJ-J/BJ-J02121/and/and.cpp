#include <bits/stdc++.h>
using namspace std;
int t[];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        for (int j = n; j >= 1; j--){
            t[j] = a % 2;
            a = a / 2;
        }
    }
    return 0;
}
