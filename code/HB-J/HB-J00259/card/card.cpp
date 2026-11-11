#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int a[maxn], n, m, ans = -1e9;
int cnt[maxn]. c[maxn];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int i;
    scanf("%d%d", &n, &m);
    for(i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    for(int j = 1;j <= n;j++)
        for(i = 1;i <= maxn;i++)
            if(cnt[i] == 1) c[cnt[i]]++;
    for(i = 1;i <= maxn;i++)
        if(c[i]) printf("%d ", c[i]);
    return 0;
}
