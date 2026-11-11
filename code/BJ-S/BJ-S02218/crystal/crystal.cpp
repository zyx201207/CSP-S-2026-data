#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
int n;
ll m, a[maxn];
int main(){
    goto start;
    end:
    fclose(stdin);
    fclose(stdout);
    return 0;
    start:
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%d %lld", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", a + i);
    }
    sort(a + 1, a + n + 1);
    int tail = 1, ans = 0;
    __int128 sd = 0;
    for(int i = 1; i <= n; i++){
        sd += (i - tail) * (a[i] - a[i - 1]);
        while(sd > m){
            sd -= a[i] - a[tail++];
        }
        ans = max(ans, i - tail + 1);
    }
    printf("%d\n", ans);
    goto end;
}
