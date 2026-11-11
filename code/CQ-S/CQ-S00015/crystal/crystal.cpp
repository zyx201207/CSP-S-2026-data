#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500100;
ll read(){
    ll x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void write(ll x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x <= 9){
        putchar(x + '0');
        return;
    }
    write(x / 10);
    putchar(x % 10 + '0');
}

int n;
ll m, a[N], s[N];

bool check(int len){
    for (int i = 1; i <= n - len; i++){
        if(1ll * len * a[i + len] - s[i + len - 1] + s[i - 1] <= m){
            return 1;
        }
    }
    return 0;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++)
        s[i] = s[i - 1] + a[i];
    int L = 0, R = n;
    while(L + 1 < R){
        int M = (L + R) / 2;
        if(check(M))
            L = M;
        else
            R = M;
    }
    write(R);
}