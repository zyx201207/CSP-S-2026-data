#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1]){
        cout<<1;
    }
    else{
        cout<<"000";return 0;
    }
    if(((int)b[2]>67&&(int)d[2]<=67)||((int)d[2]>67&&(int)b[2]<=67)){
        cout<<"00";return 0;
    }
    else{
        cout<<1;
    }
    if(abs((int)d[2]-b[2])==1){
            
        cout<<1;
    }
    else{
        if((d[2]=='D'&&b[2]=='F')||(b[2]=='D'&&d[2]=='F')){
            cout<<1;return 0;
        }
        cout<<"0";return 0;
    }
    return 0;
}