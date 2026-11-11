#include<bits/stdc++.h>
using namespace std;
int n, l, r = 1, cnt = 1, ans;
long long a[500002], cur, m;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    cur = a[1];
    while(l <= n){
        //移动l
        cnt--;
        cur += a[l++] - a[r];
        //printf("1 %d,%d:%d %lld\n", l, r, cnt, cur);
        for(;cur <= m && r <= n; r++){
            cnt++;
            cur += (a[r + 1] - a[r]) * cnt;
            //printf("2 %d,%d:%d %lld\n", l, r, cnt, cur);
        }
        ans = max(ans, cnt);
    }
    printf("%d", ans);
}
