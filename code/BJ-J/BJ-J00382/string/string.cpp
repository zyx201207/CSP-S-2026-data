#include<bits/stdc++.h>
using namespace std;
const int N = 200001;
int n, cur, lptr, rptr;
long long a[N], l, r, ans;
char c[N];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %c", &cur, &c[i]);
        a[i] = a[i - 1] + cur;
        //a[i-1] + 1 ~ a[i] 都是 c[i]
    }
    l = 1;
    r = a[n];
    lptr = 1;
    rptr = n;
    while(l <= r){
        long long val1 = a[lptr] - l + 1;
        long long val2 = r - a[rptr - 1];
        if(val1 <= val2){
            if(c[lptr] != c[rptr]){
                ans = ans + val1;
            }
            l += val1;
            r -= val1;
            lptr++;
        }else{
            if(c[lptr] != c[rptr]){
                ans = ans + val2;
            }
            l += val2;
            r -= val2;
            rptr--;
        }
        //printf("%d ", ans);
    }
    printf("%d", ans);
    return 0;
}
