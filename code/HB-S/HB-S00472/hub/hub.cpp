#include<bits/stdc++.h>
using namespace std;
int c,T;
int main(){
    //nb
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    for(int i=1;i<=T;i++){
        if(i<=2) cout<<i<<endl;
        else cout<<(i-1)*(i-1)<<endl;
    }
}
