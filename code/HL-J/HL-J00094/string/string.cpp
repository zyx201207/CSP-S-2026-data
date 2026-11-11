#include <bits/stdc++.h>
using namespace std;
int a[200007];
char c[200007];
bool ok = true;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    long long k = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        k += a[i];
    }
    for(int i = 1; i <= n - 1; i++){
        if(c[i] != c[i + 1]){
            ok = false;
            break;
        }
    }
    if(ok) cout << "0";
    else cout << k / 2 << endl;
    return 0;
}
