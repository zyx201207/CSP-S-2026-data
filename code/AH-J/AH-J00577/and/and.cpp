#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,m,a[N],ans = INT_MIN;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(m == 1){
        for(int i=1;i<=n;i++) ans = max(ans,a[i]);
        cout << ans;
        return 0;
    }
    if(m == 2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans = max(ans,a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    ans = INT_MAX;
    for(int i=1;i<=n;i++) ans = min(ans,a[i]);
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
