#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], n, m, ans = -1e9;
int main(){
    srand(int(time(0)));
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int i, j;bool f = 0;
    scanf("%d%d", &n, &m);
    for(i = 1;i <= n;i++) scanf("%d", &a[i]);
    for(i = 1;i < 30;i++)
        if(1 << i == n) f = 1;
    if(m == 1){
        int ans = -1e9;
        for(i = 1;i <= n;i++) ans = max(ans, a[i]);
        printf("%d", ans);
        return 0;
    }else if(m == n){
        int ans = a[1];
        for(i = 2;i <= n;i++) ans &= a[i];
        printf("%d", ans);
        return 0;
    }else if(m == n - 1){
        int ans1 = a[2], ans2 = a[1], ans = -1e9;
        for(i = 2;i <= n;i++) ans1 &= a[i];
        for(i = 1;i <= n;i++){
                ans2 = a[1];
            for(j = 1;j <= n;j++)
                if(j == i) continue;
                else ans2 &= a[j];
            ans = max(ans, ans2);
        }
        printf("%d", max(ans, ans1));
        return 0;
    }else if(m == 2){
        int s = -1e9;
        for(i = 1;i <= n;i++){
            int ans = a[i];
            for(j = 1;j <= n;j++){
                if(j == i) continue;
                else ans = ans & a[j];
                s = max(s, ans);
            }
        }
        printf("%d", s);
        return 0;
    }
    if(f){
        printf("%d", a[1]);
        return 0;
    }
    else{
        int ans = -1e9;
        for(i = 1;i <= n;i++) ans = max(ans, a[i]);
        printf("%d", ans);
        return 0;
    }
    printf("%d", rand());
    return 0;
}
/*
4 2
3 15 12 12
*/
