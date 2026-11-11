#include <bits/stdc++.h>
using namespace std;
int n, m;
int t_to_b(int n){
    int b = 0;
    while (n){
        b *= 10;
        b += n % 2;
        n /= 2;
    }
    return b;
}
int and(int a, int b){
    int ans;
    while (a >= 0 && b >= 0){
        ans *= 10
        ans += max(a % 10, b % 10);
        if (a == 0 && b == 0){
            break;
        }
    }
    return ans;
}
int main (){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    int a[n + 5] = {};
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int binary_ints[n + 5];
    for (int i = 1; i <= n; i++){
        binary_ints[i] = t_to_b(a[i]);
    }
    return 0;
}
