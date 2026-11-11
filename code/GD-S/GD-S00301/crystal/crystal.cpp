#include<bits/stdc++.h>
#define mem(a, v) memset(a, v, sizeof(a))

using namespace std;

const int maxn = 5e5 + 10;

int n, res = 0;
long long m;
long long a[maxn], pre[maxn];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d %lld", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
        int l = 1, r = i;
        while (l < r){
            const int mid = l + r >> 1;
            a[i] * (i - mid + 1) - (pre[i] - pre[mid - 1]) <= m ? r = mid : l = mid + 1;
        }
        res = max(res, i - l + 1);
    }
    printf("%d", res);

return 0;
}