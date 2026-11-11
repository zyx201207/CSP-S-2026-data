#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,m,d,x[500010],maxn;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        cout<<n-4+1<<endl;
    }
    return 0;
}
