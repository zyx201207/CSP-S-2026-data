#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){
        int n,k;cin>>n>>k;
        if(c==13 || c==14){
            for(int i=1,u,v; i<n; i++) cin>>u>>v;
            if(k==1) cout<<n/2/2+1<<"\n";
            else cout<<(n/2+1-k)/4+1<<"\n";
            continue;
        }
    }
    return 0;
}
//18:21 10pts?
//tot 100+100+16+10
