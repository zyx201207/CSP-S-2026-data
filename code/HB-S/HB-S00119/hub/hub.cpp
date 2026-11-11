#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5;
int c,t;
int n,k;
int u[N],v[N];
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            cin>>u[i]>>v[i];
            ans=min(ans,(u[i]+v[i])/2);
        }
        cout<<ans<<endl;
    }
    return 0;
}
