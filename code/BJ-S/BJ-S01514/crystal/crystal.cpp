#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 5e+5 + 5;
ll a[maxn], pre[maxn];

inline ll read() {
    ll ref = 0; bool f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = 0; ch = getchar();}
    while(isdigit(ch)) ref = (ref << 1) + (ref << 3) + (ch ^ 48), ch = getchar();
    return f ? ref : -ref;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n = read(); ll m = read();
    int answer = 0;
    for(int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    for(int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while(l < r){
            int mid = l + r >> 1;
            if((i - mid) * a[i] - pre[i - 1] + pre[mid - 1] > m) l = mid + 1;
            else r = mid;
        } answer = max(i - l + 1, answer);
    } cout << answer;

    return 0;
}


//1. 龙long
//2. 数组空间
//3. 手搓阳历
