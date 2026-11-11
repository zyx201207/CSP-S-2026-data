#include <bits/stdc++.h>
using namespace std;
int c,t,n,m,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> m;
        int ans=n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=n;i++){
            if(a[i]-a[1]<=m) ans--;
        }
        cout << ans << endl;
    }
    return 0;
}
