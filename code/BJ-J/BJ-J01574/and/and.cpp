#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e8 + 1;
long long n , m;
int a[maxn];
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin >> n >> m;
    int cnt = -1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt = max(cnt , a[i]);
    }
    int sum = 0;
    if(m == 2){
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                sum = max(sum , a[i] & a[j]);
            }
        }
        cout << sum;
        sum = 0;
        return 0;
    }
    if(m == 1){
        cout << cnt;
        return 0;
    }
    int ans = 33554431;
    if(m == n){
        for(int i = 1; i <= n; i++){
            ans &= a[i];
        }
        cout << ans;
        ans = 33554431;
        return 0;
    }
    if(m == n - 1){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i != j){
                    ans &= a[j];
                }
            }
            sum = max(sum , ans);
        }
        cout << sum;
    }
    return 0;
}
