#include<bits/stdc++.h>
using namespace std;
long long c,t,u,v,ans,n,d;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n-1;i++){
            cin>>u>>v;
        }
        if(n%2==0){
            ans=(n-2)/d-1;
        }
        else{
            ans=(n-1)/d-1;
        }
        cout<<ans<<endl;
    }
}
