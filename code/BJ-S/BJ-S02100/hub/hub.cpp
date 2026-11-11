#include <bits/stdc++.h>
using namespace std;
int c,t,vis=0,a,b;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,k;
        cin>>n>>k;
        int u[10001],v[10001];
        for(int i=1;i<n;i++){
            cin>>u[i]>>v[i];
            if(vis==0){
                a=u[i];
                b=v[i];
                vis=1;
                cout<<a<<endl<<b;
            }
        }
    }
    return 0;
}
