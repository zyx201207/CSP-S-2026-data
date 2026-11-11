#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,v[1000005],u[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k;
        for(int j=1;j<n;j++){
            cin>>v[i]>>u[i];
        }
    }
    cout<<k;
    return 0;
}
