#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+6;

int a[N];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while (t--){
        int n,d;
        cin>>n>>d;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cha=a[2]-a[1];
        if (d==cha*2) cout<<n-3<<'\n';
        else cout<<0<<'\n';
    }
}
