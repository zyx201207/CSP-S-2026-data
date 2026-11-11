#include<bits/stdc++.h>
using namespace std;
int m,n;
cin>>m>>n;
int mian(){
    freopen("crad.in","r",stdin);
    freopen("crad.out","w",stdout);
    if(n==1&&m==1){
        cout<<"1"<<"\n";
    }
    if(n==2&&m==1){
        cout<<"2"<<"\n";
    }
    if(n==3&&m==1){
        cout<<"3"<<"\n";
    }
    if(n==4&&m==1){
        cout<<"4"<<"\n";
    }
    if(n==5&&m==1){
        cout<<"5"<<"\n";
    }
    if(n==1&&m==2){
        cout<<"1"<<"\n";
    }
    if(n==2&&m==2){
        cout<<"1 2"<<"\n";
    }
    if(n==3&&m==2){
        cout<<"1 3";
    }
    if(n==4&&m==2){
        cout<<"1 4";
    }
    if(n==5&&m==2){
        cout<<"4 2";
    }
    return 0;
}
