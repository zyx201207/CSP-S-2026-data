#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 2e5 + 10;
ll n, a[MAXN];
char b[MAXN][5];

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++){
        scanf("%lld%s", a + i, b[i] + 1);
    }

    ll ans = 0;
    for(ll i = 1, j = n; i < j; i++){
        while(j > i && a[i] > 0){
            if(a[i] >= a[j]){
                if(b[i][1] != b[j][1]){
                    ans += a[j];
                }
                a[i] -= a[j];
                a[j] = 0;
                j--;
            }
            else{
                if(b[i][1] != b[j][1]){
                    ans += a[i];
                }
                a[j] -= a[i];
                a[i] = 0;
            }
        }
    }

    printf("%lld", ans);
    return 0;
}