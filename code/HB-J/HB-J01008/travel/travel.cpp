#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string C1,S1,C2,S2;
    cin>>C1>>S1>>C2>>S2;
    bool train=false,aisle=false,side=false;
    if(C1==C2){
        cout<<1;
        train=true;
    }
    else cout<<0;


    if(train&&S1[1]==S2[1]&&S1[0]==S2[0]){
        cout<<1;
        aisle=true;
    }
    else cout<<0;


    if(S1[2]<='C'&&S2[2]<='C'&&aisle){
        cout<<1;
        side=true;
    }else if(S1[2]>='D'&&S2[2]>='D'&&aisle){
        cout<<1;
        side=true;
    }else{
        cout<<0;
    }


    if(abs((int)S1[2]-(int)S2[2])==1&&side){
        cout<<1;
    }else if(S1[2]=='D'&&S2[2]=='F'&&side){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
