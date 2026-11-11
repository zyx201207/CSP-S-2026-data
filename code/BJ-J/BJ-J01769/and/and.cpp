#include<bits/stdc++.h>
using namespace std;
int f[200005];
int a[200005];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int m,n;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (m == n){
        int ans = a[1];
        for(int i=2;i<=n;i++){
            ans = ans & a[i];
        }
        cout << ans;
    }
    if (m == 1){
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans = max(ans, a[i]);
        }
        cout << ans;
    }
    if (m == 2){
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++)ans = max(ans, a[i] & a[j]);
        }
        cout << ans;
    }else{
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++) {
            f[i] = a[i];
        }
        for(int i = 1 ; i <= m; i++){
            for(int j = n;j >= 1; j--){
                f[j] = max(f[j - 1] & a[j], f[j]);
                cout<< f[j] <<" ";
            }
            cout<<endl;
        }
        int ans = 0;
        for(int j = n;j >= 1; j--){
            ans = max(ans, f[j]);
        }
        cout<< ans;
    }
    return 0;
}
