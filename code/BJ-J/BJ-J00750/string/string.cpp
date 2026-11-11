#include <bits/stdc++.h>
using namespace std;
string n;
int main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    int t , ans = 0;
    cin >> t;
    while(t--){
        int a;
        char b;
        cin >> a>> b;
        for(int i = 1;i <= a;i++){
            n += b;
        }
    }
    for(int i = 0;i < n.size() / 2;i++){
        if(n[i] != n[n.size()  - 1- i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
