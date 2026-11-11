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
constexpr int N = 5e5 + 5;
int n;
ll m,a[N],s[N],ans = -1;
ll calc(int pos){
    int x = a[pos],tmp = m,cnt = 1;
    for(int k = 19;k >= 0;k--){
        if(pos <= (1 << k)) continue;
        if(x * (1 << k) - (s[pos-1] - s[pos - (1 << k) - 1]) <= tmp){
            tmp -= x * (1 << k) - (s[pos-1] - s[pos - (1 << k) - 1]);
            cnt += (1 << k);
            pos -= (1 << k);
        }
    }
    return cnt;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n = readI(); m = readL();
    for(int i = 1;i <= n;i++) a[i] = readL();
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
    for(int i = 1;i <= n;i++){
        ll res = calc(i);
        // printf("now i = %d res = %lld\n",i,res);
        ans = max(ans,res);
    }
        
    printL(ans);puts("");
    return 0;
}