#include <bits/stdc++.h>
using namespace std;

long long read(){
    long long f = 1, x = 0;
    char c = getchar();
    while(c < '0' || '9' < c){
        if(c == '-') f = -1;
        c = getchar();
    }
    while('0' <= c && c <= '9'){
        x = (x << 3) + (x << 1) + (c - '0');
        c = getchar();
    }
    return f * x;
}

const int N = 5e5 + 5;
int n;
long long m, a[N], c[N];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    n = read(), m = read();
    for(int i = 1; i <= n; i++){
        a[i] = read();
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        c[i] = a[i] - a[i - 1];
    }
    int L = 1, R = 0;
    long long ans = 0;
    int len = 0, maxlen = 0;
    for(R = 1; R <= n; R++){
        len++;
        ans += 1ll * (len - 1) * c[R];
        while(ans > m && L <= R){
            ans -= a[R] - a[L];
            L++;
            len--;
        }
#ifdef Ken
        cout << "[" << L << ", " << R << "] len : " << len << "\n";
#endif
        maxlen = max(maxlen, len);
    }
    cout << maxlen << '\n';
    return 0;
}