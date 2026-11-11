#include <bits/stdc++.h>
using namespace std;

#define finished 1

long long ans = 0;
long long c, t;
long long n, d;
long long x[2000008];
long long q[2000008], head = 0, tail = 0;

int main(){
    #if finished
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    #endif
    scanf(" %lld %lld", &c, &t);
    while(t--){
        ans = 0;
        head = 0;
        tail = 0;
        scanf(" %lld %lld", &n, &d);
        for(int i = 1; i <= n; i++){
            scanf(" %lld", &x[i]);
        }
        for(int i = 1; i <= n; i++){
            if(x[i + 3] - x[i] > d && x[i + 3] - x[i + 2] <= d && x[i + 2] - x[i] <= d && x[i + 3] - x[i + 1] <= d){
                ans++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}