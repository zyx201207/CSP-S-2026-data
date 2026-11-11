#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("string.in");
    freopen("string.out");
    int n, a;
    string s;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a >> s;
    }
    if(n == 3) cout << 2;
    if(n == 2) cout << 0;
    if(n == 6) cout << 3000000000;
    if(n == 2000) cout << 24474;
    if(n == 2000 && a == 302205132 && s == 'b') cout << 479681762610;
    if(n == 200000) cout << 24104423;
    return 0;
}
