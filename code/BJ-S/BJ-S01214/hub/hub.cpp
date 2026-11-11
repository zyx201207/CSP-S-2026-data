#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
        }
        n/=2;
        int t1=n/2+(n%2)-k/2+(k%2);
        int t2=n/2-k/2;
        int ans=max(t1/2+(t1%2)+1,t2/2+(t2%2)+1);
        cout<<ans<<"\n";
    }
    return 0;
}
