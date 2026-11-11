#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5+5;
inline ll read() {
    ll x = 0, f = 1;char c = getchar();
    while(c<'0'||c>'9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c>='0'&&c<='9') {
        x = x*10+(c-'0');
        c = getchar();
    }
    return f*x;
}
ll n, m, a[N];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    n = read();m = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    ll cnt[m];memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; ++i) {
        queue<ll> q;
        for(int j = i; j <= n; ++j) {
            if(q.front()==a[j]) {
                while(!q.empty()) q.pop();
            }
            q.emplace(a[j]);
        }
        while(!q.empty()){
            ++cnt[q.front()];
            q.pop();
        }
    }
    for(int i = 1; i <= m; ++i) cout << cnt[i] << " ";
    return 0;
}