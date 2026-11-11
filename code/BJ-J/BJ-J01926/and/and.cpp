#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(m == 1){
        for(int i = 1;i <= n;i++){
            int x;
            cin >> x;
            ans = max(ans,x);
        }
        cout << ans;
        return 0;
    }
    if(m == n){
        for(int i = 1;i <= n;i++){
            int x;
            cin >> x;
            ans = ans & x;
        }
        cout << ans;
        return 0;
    }
    if(m == 2){
        int a[n + 5];
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                ans = max(ans,a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    cout << 0;
    return 0;
}
