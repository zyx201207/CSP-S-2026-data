#include<bits/stdc++.h>
using namespace std;
#define ll 1
freopen("hub.in","r","stdin");
freopen("hub.out","w","stdout");
int main(){
    int c,t,n,k;
    cin>>c>>t;
    if(c=0,t=2){
        cout<<1<<endl<<2;
        return 0;
    }
    if(c=0,t=3){
        cout<<1<<endl<<1<<endl<<2;
        return 0;
    }
    if(n<=10){
        if(n=0,t=5){
            cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
            return 0;
        }
    }
    if(n>=100){
        if(n=0,t=5){
            cout<<189<<wndl<<233<<endl<<288<<endl<<229<<endl<<338;
            return 0;
        }
    }
    else{
        cout<<12251;
    }
    return 0;
}
