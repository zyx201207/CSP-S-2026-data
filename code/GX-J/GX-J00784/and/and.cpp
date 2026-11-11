#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005],ans;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ans = a[n];
    if(m == 1) cout << ans;
    else if(m == n){
        for(int i = n-1;i >= 1;i--){
            ans &= a[i];
        }
        cout << ans;
    }else{
        for(int i = n-1;i >= n-m+1;i--){
            ans &= a[i];
        }
        cout << ans;
    }
    return 0;
}
