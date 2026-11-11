#include <bits/stdc++.h>
using namespace std;
int n,c,t,k,U,V,vis[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        int maxx=0;
        for(int i=1;i<=n;i++)
        {
            cin>>U>>V;
            vis[U]++;
            vis[V]++;
            maxx=max(maxx,max(vis[V],vis[U]));
        }
        if(n==k){
            cout<<0<<endl;
        }
        else if(n/k<=2){
            cout<<1<<endl;
        }
        else if((maxx+k-1>n/2)){
            cout<<1<<endl;
        }
        else{
            cout<<2<<endl;
        }
    }
    return 0;
}
