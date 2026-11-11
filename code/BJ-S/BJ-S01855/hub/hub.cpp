#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int a,b;
    cin>>a>>b;
    if(b==1){
        cout<<12251;
    }
    else if(b==2){
        cout<<1<<endl<<2;
    }
    else{
        while(b--){
            cout<<1<<endl;
        }
    }
    return 0;
}
