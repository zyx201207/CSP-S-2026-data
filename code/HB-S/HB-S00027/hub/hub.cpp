#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n-1;++i){
            int a,b;
            cin>>a>>b;
        }
        int all=(n-1)/2;
        for(int i=all,ans=1;i>=1;i-=2,++ans){
            if(i<=k){
                cout<<ans/2+1<<endl;
                break;
            }
        }
    }
    return 0;
}
