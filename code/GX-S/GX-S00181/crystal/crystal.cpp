#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], big = 0;
struct AAA{
    long long c;
};
AAA dp[500005];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        dp[i].c = 0;
    }
    dp[0].c = 1;
    sort(a, a + n);
    for(int i = 1; i < n; i++){
        m = m - (a[i] - a[i-1]) * dp[i-1].c;
        dp[i].c = dp[i-1].c + 1;
        while(m < 0){
            m += a[i] - a[i - dp[i].c + 1];
            dp[i].c--;
        }
        big = max(big, dp[i].c);
    }
    printf("%lld", big);
    return 0;
}
