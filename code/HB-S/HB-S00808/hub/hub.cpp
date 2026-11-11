#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,u[100005],v[100005],n,k,sum=0;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        for(int j=0;j<n;j++){
            cin>>u[i]>>v[i];
        }
    }
    for(int i=0;i<n;i++){
        sum+=u[i];
    }
    cout<<sum/2;
    return 0;
}
