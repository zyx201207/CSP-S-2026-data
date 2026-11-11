#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++)cin>>u>>v;
        if(n==k)cout<<0<<endl;
        else if(n==k-1)cout<<1<<endl;
        else cout<<n-k-1<<endl;
    }
    return 0;
}
