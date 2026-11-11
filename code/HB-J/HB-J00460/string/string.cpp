#include <bits/stdc++.h>
using namespace std;
long long n, L;
string s;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    while (n --){
        int x;
        char c;
        cin >> x >> c;
        for (int i = L + 1;i <= L + x;++ i) s[i] = c;
        L += x;
    }
    long long cnt = 0;
    for (int i = 1;i <= (L - (L % 2 == 1)) / 2;++ i){
        if (s[i] != s[L + 1 - i]) cnt ++;
    }
    cout << cnt;
    return 0;
}
