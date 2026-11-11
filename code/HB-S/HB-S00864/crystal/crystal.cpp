#include <bits/stdc++.h>
using namespace std;

#define finished 1

long long n, m;
long long a[500008];
long long ans = 0;
long long used = 0, dv[500008];
long long ans2 = 0;

int cmp(const void *p1, const void *p2){
    long long *a = (long long *)p1;
    long long *b = (long long *)p2;
    if(*a > *b){
        return 1;
    }
    return 0;
}

long long lmax(long long b, long long c){
    return b > c ? b : c;
}

int main(){
    #if finished
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    #endif
    scanf(" %lld %lld", &n, &m);
    dv[0] = 0;
    for(int i = 1; i <= n; i++){
        scanf(" %lld", &a[i]);
    }
    qsort(&a[1], n, sizeof(long long), cmp);
    for(int i = 1; i <= n; i++){
        dv[i] = a[i] - a[i - 1];
    }

    #if !finished
    for(int i = 1; i <= n; i++){
        printf("%lld ", dv[i]);
    }
    printf("\n");
    #endif

    long long i = 1;
    ans++;
    while(used <= m){
        i++;
        if(used + dv[i] * (i - 1) <= m){
            used += dv[i] * (i - 1);
            ans++;
        }
        else{
            break;
        }
    }
    printf("%lld\n", ans);
    #if !finished
    printf("out position: %lld\nans position: %lld\n", a[313324], a[315275]);
    printf("%lld\n", used);
    printf("%lld\n", used + dv[i] * (i - 1));
    #endif
    return 0;
}