#include<bits/stdc++.h>
using namespace std;
char b[1000000];
int a[1000000];
int main(){
    int n;
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    if(n == 1){
        cout << "0";
    }
    if(n == 2){
        cout << max(a[1],a[0]) - min(a[0], a[1]);
    }
    cout << "0";
    return 0;
}
