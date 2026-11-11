#include <bits/stdc++.h>
using namespace std;
int n, a[200005], x[2];
long long sum, num[2], ans;
char c[200005], s[2];
main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d %c", &a[i], &c[i]);
        sum += a[i];
    }
    x[1] = n;
    num[1] = a[n];
    s[1] = c[n];
    while (num[0]+num[1] < sum){
        if (num[1] > num[0]){
            while (1){
                x[0]++;
                num[0] += a[x[0]];
                s[0] = c[x[0]];
                if (num[0] < num[1]){
                    if (s[0] != s[1])
                        ans += a[x[0]];
                }
                else{
                    if (s[0] != s[1])
                        ans += num[1]-num[0]+a[x[0]];
                    break;
                }
            }
        }
        else{
            while (1){
                x[1]--;
                num[1] += a[x[1]];
                s[1] = c[x[1]];
                if (num[1] < num[0]){
                    if (s[1] != s[0])
                        ans += a[x[1]];
                }
                else{
                    if (s[1] != s[0])
                        ans += num[0]-num[1]+a[x[1]];
                    break;
                }
            }
        }
    }
    printf("%lld", ans);
    return 0;
}