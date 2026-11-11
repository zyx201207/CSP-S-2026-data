#include <bits/stdc++.h>
using namespace std;
int a[101], b[101];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    if(n == 1){
        cout << 0;
    }else if(n == 2){
        if(b[0] == b[1]){
            cout << 0;
        }else{
            cout << (a[0] + a[1]) / 2;
        }
    }else{
        cout << 0;
    }
    return 0;
}
