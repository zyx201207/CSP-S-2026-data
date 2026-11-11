#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[343411],v[234211],ans=0,f=0;
int main(){
    freopen("hub","r",stdin);
    freopen("hub","w",stdout);
    cin>>c>>t;
    cin>>n>>k;
    for(int i=0;i<=n;i++){
        cin>>u[i]>>v[i];
    }
    if(n<5){
        for(int i=0;i<=n;i++){
            ans++;
        }
        for(int i=0;i<=k;i++){
            f++;
        }
    }
    cout<<ans<<endl<<f;
    return 0;
}
