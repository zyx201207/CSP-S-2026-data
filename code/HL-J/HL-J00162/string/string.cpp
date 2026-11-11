#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("string.in", "r", stdin);
    //freopen("string.out", "w", stdout);
    int n, cnt = 0, a = 0;
    cin >> n;
    string s[n], si[n];
    int ge[n];
    for(int i = 1; i <= n; i++){
        cin >> ge[i] >> si[i];
        cnt += ge[i];
    }
    for(int i = cnt; i >= 1; i--){
        for(int j = 1; j <= cnt; j++){
            s[i] = si[j];
        }
    }
    for(int i = 1; i <= cnt; i++){
        if(s[i] != si[i]){
            a++;
        }
    }
    int b = a / 2;
    cout << b;
    return 0;
}
