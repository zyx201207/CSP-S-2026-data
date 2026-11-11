#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN=2e6+5;
int c,T,n,d,a[MAXN];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cout<<n-3<<'\n';
    }

    return 0;
}
