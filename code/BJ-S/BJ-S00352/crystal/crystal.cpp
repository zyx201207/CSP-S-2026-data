#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long m, a[500005];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d %lld", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    int l = 0, r = 0, sum = 0, ans = 0;
    while(1){
        if(sum <= m){
            r++;
            if(r >= n){
                break;
            }
            if(ans < r - l){
                ans = r - l;
            }
            sum += (r - l) * (a[r] - a[r - 1]);
        }else{
            sum -= a[r] - a[l];
            l++;
        }
    }
    printf("%d", ans);
    return 0;
}
