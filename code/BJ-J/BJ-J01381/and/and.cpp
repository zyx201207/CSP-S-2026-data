#include <bits/stdc++.h>
using namespace std;

int read(){
    int f = 1, x = 0;
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

const int N = 2e5 + 5;
int n, m;
int a[N], vis[N], b[N];
int ans;

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    n = read(), m = read();
    for(int i = 1; i <= n; i++){
        a[i] = read();
    }
    for(int i = 29; i >= 0; i--){
        int sum = 0;
        for(int j = 1; j <= n; j++){
            b[j] = 0;
        }
        for(int j = 1; j <= n; j++){
            if(vis[j] == 0 && (a[j] & (1 << i))){
                sum++;
                b[j] = 1;
            }
        }
        if(sum >= m){
            ans += (1 << i);
            for(int j = 1; j <= n; j++){
                if(vis[j] == 0 && b[j] == 0){
                    vis[j] = 1;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}