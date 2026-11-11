#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int a, aa, b[200005];
    int cnt = 0;
    string d = "", e = "", f = "", c[200005];
    cin >> a;
    for(int i = 1 ; i <= a ; i++){
        cin >> b[i] >> c[i];
        aa+=b[i];
    }for(int i = 1 ; i <= a ; i++){
        for(int j = 1 ; j <= b[i] ; j++){
            d = d + c[i];
        }
    }
    if(aa%2==0){
        for(int i = aa/2-1 ; i >= 0 ; i--){
            e = e + d[i];
        }for(int i = aa/2 ; i <= aa ; i++){
            f = f + d[i];
        }
        for(int i = 1 ; i <= aa/2 ; i++){
            if(e[i] != f[i]) cnt++;
        }cout << cnt;
    }else{
        for(int i = aa/2-1 ; i >= 0 ; i--){
            e = e + d[i];
        }for(int i = aa/2+1 ; i <= aa ; i++){
            f = f + d[i];
        }for(int i = 1 ; i <= aa/2 ; i++){
            if(e[i] != f[i]) cnt++;
        }cout << cnt;
    }
    return 0;
}
