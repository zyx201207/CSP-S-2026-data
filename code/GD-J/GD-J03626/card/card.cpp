#include<bits/stdc++.h>


const int MAXN = 5e5 + 10;
long long n, m, idx;
long long a[MAXN];
long long last[MAXN];
long long cnt[MAXN];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for(int i = 1;i <= n;i++){
        scanf("%lld", a + i);
        last[a[i]] = i;
    }
    for(int i = 1;i <= n;i++){
        idx = i;
        while(idx <= n) cnt[a[idx]]++, idx = last[a[idx]] + 1;
    }
    for(int i = 1;i <= m;i++) printf("%lld ", cnt[i]);

    return 0;
}