#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("hub","r",stdin);
    freopen("hub","w",stdout);
    int c,t,n,k,s[1000005],u[10005],v[10005];
    cin>>c>>t;
    cin>>n>>k;
    for(int i=1;i<=t*n;i++){
        cin>>u[i]>>v[i];
        for(int i=1;i<=t*n-1;i++){
            if(u[i]+v[i]<u[i-1]+v[t-1]){
                s[0]=u[i];
                s[1]=v[i];
            }
        }
    }

cout<<s[0]<<endl<<s[1];
    return 0;
}
