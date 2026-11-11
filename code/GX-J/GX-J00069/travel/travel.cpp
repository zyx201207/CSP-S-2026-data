#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2;
    char b1,b2;
    cin>>a1>>b1>>a2>>b2;
    if(a1!=a2){
        cout<<0000;
    }
    else if(a1==a2){
        cout<<1;
    }
    else if(b1-b2<6){
        cout<<1;
    }
    else if(b1-b2>=6){
        cout<<000;
    }
    else if(b1-b2<3){
        cout<<1;
    }
    else if(b1-b2>=3){
        cout<<00;
    }
    else if(b1-b2==1){
        cout<<1;
    }
    else{
        cout<<1111;
    }
    return 0;
}
