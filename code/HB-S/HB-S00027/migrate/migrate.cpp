#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,a,b;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k>>a>>b;
        for(int i=3;i<=n;++i){
            int d;
            cin>>d;
        }
        int r=b-a,ptm=k/r;
        if(ptm==0||ptm==1)cout<<0<<endl;
        else cout<<max(n-1-ptm-(ptm-1)+1,0ll)<<endl;
    }
    return 0;
}
