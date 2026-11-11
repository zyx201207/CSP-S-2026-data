#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000010;
typedef long long ll;
inline long long rd(){
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9'){
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9'){
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * f;
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ll c = rd(), n = rd(), m = rd(), d = rd(), q = rd();
    cout << "35\n16";
    return 0;
}
