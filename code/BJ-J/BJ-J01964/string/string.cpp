#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, a[200000];
    string b[200000];
    bool s = true;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i < n; i++){
        if (b[i-1] != b[i]){
            s = false;
        }
    }
    if (b){
        cout << 0 << '\n';
    }
    return 0;
}
