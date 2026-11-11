#include <bits/stdc++.h>
using namespace std;
int main(){
    int c , t;
    cin >> c >> t;
    while(t --){
        int n , d;
        cin >> n >> d;
        vector<int> a(n + 1);
        for(int i = 1;i <= n;i ++){
            cin >> a[i];
        }
        int s = a[2] - a[1];
        if(d >= 3*s || d < 2 * s){
            cout << 0;
        }else{
            if(n - 3 <= 0) cout << 0;
            else cout << n - 3;
        }
    }
    return 0;
}