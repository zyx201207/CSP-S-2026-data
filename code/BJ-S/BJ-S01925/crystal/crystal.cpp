#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
    long long cnt = 0, ans = 1, cnt1 = 1;
    sort(a+1, a+n+1);
    for(int i = 2;i <= n;i++){
        if(m >= cnt + cnt1 * (a[i] - a[i-1])){
            cnt += cnt1 * (a[i] - a[i-1]);
            cnt1++;
            ans = max(ans, cnt1);
        }
        else{
            while(m < cnt + cnt1 * (a[i] - a[i-1])){
                cnt -= a[i-1] - a[i-cnt1];
                cnt1--;
            }
            cnt += cnt1 * (a[i] - a[i-1]);
            cnt1++;
            ans = max(ans, cnt1);
        }
    }
    printf("%d", ans);
    return 0;
}
