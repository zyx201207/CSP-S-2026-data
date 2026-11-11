#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int a[MAXN];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m; cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(m == 1){
        int ans = 0;
        for(int i = 1;i <= n;i++) ans = max(a[i],ans);
        cout << ans;
    }
    else if(m == 2){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j < i;j++){
                int t = a[i] & a[j];
                ans = max(ans,t);
            }
        }
        cout << ans;
    }
    else if(m == 3){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j < i;j++){
                for(int k = 1;k < j;k++){
                    int t = a[i] & a[j] & a[k];
                    ans = max(t,ans);
                }
            }
        }
        cout << ans;
    }
    else if(m == 4){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j < i;j++){
                for(int k = 1;k < j;k++){
                    for(int c = 1;c < k;c++){
                        int t = a[i] & a[j] & a[k] & a[c];
                        ans = max(ans,t);
                    }
                }
            }
        }
        cout << ans;
    }
    else if(m == n){
        int sum = 0,ans = 0;
        for(int i = 1;i <= n;i++){
            sum &= a[i];
        }
        cout << sum;
    }
    return 0;
}
