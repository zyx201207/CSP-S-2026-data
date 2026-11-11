#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int n , m , a[N];
bool wei[N][35];
bool f[N];
int ans;
int main() {
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    scanf("%d %d" , & n , & m);
    for(int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , & a[i]);
    }
    sort(a + 1 , a + 1 + n);
    for(int i = 1 ; i <= n ; ++ i) {
        int b = a[i] , id = 0;
        while(b) {
            wei[i][id] = b & 1;
            b >>= 1;
            id ++;
        }
    }
    for(int i = 1 ; i <= n ; ++ i) {
        f[i] = 1;
    }
    for(int i = 31 ; i >= 0 ; -- i) {
        int sum = 0;
        for(int j = 1 ; j <= n ; ++ j) {
            if(wei[j][i] && f[j]) {
                sum ++;
            }
        }
        if(sum >= m) {
            for(int j = 1 ; j <= n ; ++ j) {
                if(! wei[j][i]) {
                    f[j] = 0;
                }
            }
        }
    }
    for(int i = 1 ; i <= n ; ++ i) {
        if(f[i]) {
            if(ans == 0) {
                ans = a[i];
            }
            ans &= a[i];
        }
    }
    printf("%d" , ans);
    return 0;
}
