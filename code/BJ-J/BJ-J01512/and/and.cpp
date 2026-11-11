#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005], ans;
bool chk(int x){
    int cnt = 0;
    for(int i = 1;i <= n;i++) if((a[i] & x) == x) cnt++;
    if(cnt >= m) return 1;
    return 0;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
    for(int i = 30;i >= 0;i--)
        if(chk(ans + (1 << i))) ans += (1 << i);
    printf("%d", ans);
    return 0;
}
