#include <bits/stdc++.h>
using namespace std;

string sr1,sr2,sx1,sx2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>sr1>>sr2>>sx1>>sx2;
    int ar=10*(sr1[0]-'0')+sr1[1]-'0';
    int br=10*(sr2[0]-'0')+sr2[1]-'0';
    int cr=sr2[2]-'A';
    int ax=10*(sx1[0]-'0')+sx1[1]-'0';
    int bx=10*(sx2[0]-'0')+sx2[1]-'0';
    int cx=sx2[2]-'A';
    if(ar!=ax){
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<"1";
    if(br!=bx){
        cout<<"000"<<endl;
        return 0;
    }
    cout<<"1";
    if(cr<=2&&cx>=3||cr>=3&&cx<=2){
        cout<<"00"<<endl;
        return 0;
    }
    cout<<"1";
    if(abs(cr-cx)!=1||cr+cx==5){
       cout<<"0"<<endl;
        return 0;
    }
    cout<<"1";
    cout<<endl;
    return 0;
}
