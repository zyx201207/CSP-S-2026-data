#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rd read()
#define pii pair<int,int>
#define fo(a,b,c) for(int a=(b); a<=(c);++a)
#define of(a,b,c) for(int a=(b); a<=(c);--a)
#define pb push_back
#define enter putchar('\n')
const int N =5e5+7, M = 1e5+7, INF = 0x3f3f3f3f;
inline int read() {
    int x = 0,f=1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-')f=-1; ch = getchar();}
    while (ch >='0' && ch <='9') {x=x*10+ch-'0';ch = getchar();}
    return x*f;
}
// g++ crystal.cpp -o crystal -std=c++14 -O2 -Wall
int n, d;
int a[N];
int diff;
void Input() {
    n = rd, d = rd;
    fo (i, 1, n) {
        a[i] = rd;
    }
    diff = a[n]-a[n-1];
}
void answer() {

}
void solve() {
    Input();
    ll k = d/diff;
    printf("%lld\n", (n-k)*(d-1));
    answer();
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c = rd, t = rd;
    while (t--) solve();
    return 0;
}