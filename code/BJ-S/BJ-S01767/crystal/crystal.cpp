#include<bits/stdc++.h>
using namespace std;
int n;
long long m, a[500005];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }
    if(n <= 5){
        cout << n - 1;
        return 0;
    }
    if(m >= n * (n + 1) / 2){
        cout << n;
        return 0;
    }
    for(int i = 1; i < n; i++){
        if(m >= i * (i + 1) / 2 && m < (i + 1) * (i + 2) / 2){
            cout << i + 1;
            return 0;
        }
    }
    return 0;
}
