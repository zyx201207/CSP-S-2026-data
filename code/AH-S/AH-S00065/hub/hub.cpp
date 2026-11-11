#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,m,u,v;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(ll i=1;i<n;i++) cin>>u>>v;
        cout<<n-1<<endl;
    }
    return 0;
}
