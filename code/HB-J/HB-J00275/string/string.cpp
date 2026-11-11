#include <bits/stdc++.h>

using namespace std;
const long long N = 2e5 + 5;
long long n , a[N];
char c[N];
long long ans , l;
int main() {
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    scanf("%lld" , & n);
    for(long long i = 1 ; i <= n ; ++ i) {
        scanf("\n%lld %c" , & a[i] , & c[i]);
        l += a[i];
    }
    long long si = 0 , sj = 0;
    for(long long i = 1 , j = n ; i < j ;) {
        long long sn = 1;
        if(c[i] == c[j]) {
            sn = 0;
        }
        if(a[i] >= a[j]) {
            ans += a[j] * sn;
            a[i] -= a[j];
            j --;
        } else {
            ans += a[i] * sn;
            a[j] -= a[i];
            i ++;
        }
    }
    printf("%lld" , ans);
    return 0;
}
