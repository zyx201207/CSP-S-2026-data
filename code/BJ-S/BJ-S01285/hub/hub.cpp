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

const int N = 20;
int n, m;
vector <int> g[N];

void work(){
    n = read(), m = read();
    for(int i = 1; i < n; i++){
        int u = read(), v = read();
    }
    cout << (n / 2 + 1) / m << '\n';
}

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c = read(), t = read();
    while(t--){
        work();
    }
    return 0;
}