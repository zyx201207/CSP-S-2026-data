#include <bits/stdc++.h>
using namespace std;
int a[500005];
int f[300005];
int b[500005];
int temp[500005];
int ans[300005];
int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--){
        f[a[i]]++;
        temp[a[i]]++;
    }
    for (int i = 1; i <= n; i++){
        temp[a[i]]--;
        if (temp[a[i]] == 0){
            ans[a[i]] = f[a[i]];
            f[a[i + 1]] += f[a[i]];
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] <<" ";
    return 0;
}
