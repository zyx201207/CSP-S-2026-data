#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    string s;
    int n, x;
    char c;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x >> c;
        while(x--){
            s += c;
        }
    }
    string b;
    reverse(s.begin(), s.end());
    b = s;
    long long cnt = 0;
    reverse(s.begin(), s.end());
    for(int i = s.size() / 2; i < s.size(); i++){
        if(s[i] != b[i]){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}