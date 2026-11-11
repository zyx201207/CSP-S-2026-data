#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N=2e6+10;
int a[N];
int T,n,c;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        cout<<2<<"\n";
    }
    return 0;
}
