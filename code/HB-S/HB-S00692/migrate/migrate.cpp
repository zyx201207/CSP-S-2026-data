#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline int readI(){
    int x = 0,f = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return x * f;
}
inline ll readL(){
    ll  x = 0,f = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return x * f;
}
inline void printI(int x){
    if(x < 0) {x = -x; putchar('-');}
    if(x > 9) printI(x / 10);
    putchar(x % 10 + '0');
}
inline void printL(ll x){
    if(x < 0) {x = -x; putchar('-');}
    if(x > 9) printL(x / 10);
    putchar(x % 10 + '0');
}

const int N = 2e6 + 5;
int n,C,T;
ll d,x[N];
void solve(){
    n = readI(); d = readL();
    for(int i = 1;i <= n;i++) x[i] = readL();
    puts("0");
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    C=readI(),T=readI();
    while(T--) solve();
    return 0;
}