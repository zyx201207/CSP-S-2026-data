#include<bits/stdc++.h>
using namespace std;
int n, id, j, k;
bool vis[2][400005];
long long a[200005], b[200005], d[400005], x[400005], ans;
char c[200005];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
        scanf("%d %c", &a[i], &c[i]);
    for(int i = 1;i <= n;i++)
       b[i] = (long long)b[i - 1] + a[n - i + 1];
    for(int i = 1;i <= n;i++)
        a[i] += a[i - 1];
    for(int i = 1;i <= n;i++)
        d[i * 2 - 1] = a[i], d[i * 2] = b[i];
    sort(d + 1, d + 2 * n + 1);
    for(int i = 1;i <= 2 * n;i++)
        if(i == 1 || d[i] != d[i - 1])
            x[++id] = d[i];
    for(int i = 1;i <= n;i++){
        while(a[i] > x[j]) j++;
        while(b[i] > x[k]) k++;
        vis[0][j] = vis[1][k] = 1;
    }
    j = k = 1;
    for(int i = 1;i <= id;i++){
        if(c[j] != c[n - k + 1]) ans += (long long)x[i] - x[i - 1];
        if(vis[0][i]) j++;
        if(vis[1][i]) k++;
    }
    printf("%lld", (long long)ans / 2ll);
    return 0;
}

