#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
int n, k, u, v, c, t;
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d %d", &c, &t);
    while(t--) {
        scanf("%d %d", &n, &k);
        for(int i = 1; i < n; i++) scanf("%d %d", &u, &v);
        printf("%d\n", n / 2 + 1 - (n - k));
    }
    return 0;
}
