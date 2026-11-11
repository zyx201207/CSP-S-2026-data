#include<bits/stdc++.h>
using namespace std;
int n, m, a[200001], cnt, ans;
bool inset[200001];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        inset[i] = true;
    }
    for(int cur = 30; cur >= 0; cur--){
        cnt = 0;
        for(int i = 1; i <= n; i++){
            if(!inset[i])continue;
            if(a[i] & (1 << cur))cnt++;
        }
        if(cnt < m)continue;
        ans += (1 << cur);
        for(int i = 1; i <= n; i++){
            if(a[i] & (1 << cur))continue;
            inset[i] = false;
        }
    }
    printf("%d", ans);
}
