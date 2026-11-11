#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=2e6+10;
int c,t,n,d,a[maxn];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while (t--){
        cin>>n>>d;
        for (int i=1;i<=n;i++) cin>>a[i];
        int mx=d/(a[2]-a[1]);
        if (mx==0){
            cout << 0 << '\n';
            continue;
        }
        cout << max(0,n-2*mx+1) << '\n';
    }
    return 0;
}
