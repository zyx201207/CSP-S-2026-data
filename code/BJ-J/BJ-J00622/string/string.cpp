#include <bits/stdc++.h>
using namespace std;
int n;
long long a;
char c;
string ac;
long long cnt, cnt1;
int main (){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a >> c;
        for (int j = 1; j <= a; ++j){
            ac += c;
        }
        cnt += a;
    }
    for (int i = 0; i < cnt / 2; ++i){
        if (ac[i] != ac[cnt - i - 1]){
            cnt1++;
        }
    }
    cout << cnt1;
    return 0;
}
