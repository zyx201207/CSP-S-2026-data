#include<bits/stdc++.h>
using namespace std;
int n;
long long len = 0, r = 1;
string s = "";
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        long long num;
        char c;
        cin >> num >> c;
        len += num;
        for(int j = 1; j <= num; j++){
            s += c;
        }
    }
    long long ans = 0;
    for(int i = 0; i <= len / 2; i++){
        if(s[i] != s[len - 1 - i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
