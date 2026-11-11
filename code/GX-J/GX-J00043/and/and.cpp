#include <bits/stdc++.h>
using namespace std;
int m, n, a[200005];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }if(m == 1 && n == 1) cout << a[1];
    if(m > 2){
        if(m == n){
            int num = a[1], maxn = -5;
            for(int i = 2 ; i <= n ; i++){
                maxn = max(maxn, num^a[i]);
                num = maxn;
            }cout << num;
        }
        else{
            int maxn = 0;
            for(int i = m ; i <= n ; i++){
                maxn = max(maxn, a[m-1]^a[m]);
            }cout << maxn;
        }
    }
    return 0;
}
