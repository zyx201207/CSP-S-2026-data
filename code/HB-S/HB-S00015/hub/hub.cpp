#include<bits/stdc++.h>
using namespace std;
int power(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
            res=res*a;
        }
        a=a*a;
        b>>=1;
    }
    return res;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
        }
        int ttt=log2(k)+1;
        int wwq=(1<<ttt);
        int ans=n/wwq;
        if(ans<1)cout<<1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}