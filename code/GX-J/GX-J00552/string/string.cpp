#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string4.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, ans, lf, rt;
    long long l = 0;
    string s;
    cin >> n;
    int a[n+10];
    char c[n+10];
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i] >> c[i];
        l += a[i];
    }
    ans = l / 2;
    char left, right;
    for (int i = 1 ; i <= l / 2 ; i++){
        int suma = 0;
        for (int j = 1 ; j <= n ; j++){
                if (suma < i && i <= suma + a[j]){
                    left = c[j];
                    break;
                }
            suma += a[j];
        }
        suma = 0;
        for (int j = n ; j >= 1 ; j--){
                if (suma < i && i <= suma + a[j]){
                    right = c[j];
                    break;
                }
            suma += a[j];
        }
        if (left == right)
            ans--;
    }
    cout << ans;
    return 0;
}
