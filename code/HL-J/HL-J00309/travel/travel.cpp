#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    bool f=1;
    char x[3],y[3];
    cin>>a;
    for(int i=0;i<3;i++){
        cin>>x[i];
    }cin>>b;
    for(int i=0;i<3;i++){
        cin>>y[i];
    }
    if(a==b){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }if(x[0]==y[0]&&x[1]==y[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }if(x[2]<='C'){
        if(y[2]<='C'){
            cout<<1;
        }else{
            cout<<"00";
        return 0;
        }
    }else{
        if(y[2]<='C'){
            cout<<"00";
        return 0;
        }else{
            f=0;
            cout<<1;
        }
    }if(f){
        if((x[2]+1==y[2]&&x[2]!='C')||(y[2]+1==x[2]&&y[2]!='C')){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        cout<<0;
    }
    return 0;
}
