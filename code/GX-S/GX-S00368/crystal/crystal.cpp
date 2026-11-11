#include<bits/stdc++.h>
using namespace std;
#define int __int128

int read(){
    bool flag = 0;
    int res = 0;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') flag = 1;
        c = getchar();
    }
    while('0' <= c && c <= '9'){
        res = res * 10 + (c - '0');
        c = getchar();
    }
    if(flag) res = -res;
    return res;
}

void print(int res){
    int p = 1e32;
    if(res < 0){
        cout << '-';
        res = -res;
    }
    while(res < p) p /= 10;
    while(res){
        signed x = (res / p);
        cout << x;
        res %= p;
        p /= 10;
    }
}

const int maxn = 5e5 + 5;
const int inf = 1e18 + 9;
int a[maxn], ans[maxn];
int n, m;

bool cmp(int x, int y){
    return x < y;
}

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n = read(), m = read();
    for(int i=1;i<=n;i++) ans[i] = inf;
    ans[0] = ans[1] = 0;
    for(int i=1;i<=n;i++) a[i] = read();
    sort(a+1, a+n+1, cmp);
    int res = 1;
    int j = 1;
    for(int i=2;i<=n;i++){
        ans[i] = ans[i-1] + (a[i] - a[i-1]) * (i-j);
        while(ans[i] > m){
            ans[i] -= (a[i] - a[j]);
            j ++;
        }
        res = max(res, i-j+1);
    }
    print(res);

    return 0;
}
