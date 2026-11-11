#include<bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e5 + 5;
long long a[N];

inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-'){
            f = -1;
            ch = getchar();
        }
    }

    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

bool cmp(long long a, long long b){
    return a > b;
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a+1, a+n+1, cmp);

    long long ans = a[1];
    for(long long i = 2; i <= m; i++){
        ans = ans & a[i];
    }
    cout << ans;
}
