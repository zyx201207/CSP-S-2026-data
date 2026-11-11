#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = (a) ; i <= (b) ; i++)
// #define DEBUG
constexpr int N = 5e5 + 10;
void read(int &x){
    x = 0;
    int f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
        f = (ch == '-' ? -1 : 1), ch = getchar();
    while(ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    x *= f;
}
int n, a[N], m;
signed main(){
    #ifndef DEBUG
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    #endif 
    read(n), read(m);
    rep(i, 1, n) read(a[i]);
    sort(a + 1, a + 1 + n);
    int ans = 0;
    int l = 1, sum = 0;
    rep(i, 1, n){
        sum += (i - l) * (a[i] - a[i - 1]);
        while(sum > m){
            sum -= (a[i] - a[l]);
            l++;
        }
        ans = max(ans, i - l + 1);
    }
    printf("%lld\n", ans);
    return 0;
}