#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m, a[100000], ans = -1;
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >>a[i];
        ans = max(ans, a[i]);
    }
    if (m == 1){
        cout << ans;
        return 0;
    }
    ans = -1;
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= n;j++){
            if (i == j)continue;
            ans = max((a[i] & a[j]), ans);
        }
    }
    cout << ans;
}
