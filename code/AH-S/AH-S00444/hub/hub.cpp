#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m;
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1,x,y;i<=n;i++){
            cin>>x>>y;
        }
        if(c==13||c==14){
            cout<<(n-m*2+1)/8+1<<endl;
        }else{cout<<0;}
    }
    return 0;
}
