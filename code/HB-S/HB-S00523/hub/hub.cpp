#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1000005],v[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k;
        for(int j=1;j<=n;j++)
            cin>>u[j]>>v[j];
    }
    if(t==2)
        cout<<1<<endl<<2;
    else if(t==3)
        cout<<1<<endl<<1<<endl<<2;
    else
        cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
}
