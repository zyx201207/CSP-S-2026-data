#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a=0,b=0,e=0,d=0;
    string a1,a2,a3,a4;
    cin>>a1>>a2>>a3>>a4;
     if(a1==a3)a=1;
    else{
            cout<<"0000";
            return 0;
    }
    if(a2[0]==a4[0]&&a2[1]==a4[1]){
            b=1;
    if((a2[2]<='C'&&a4[2]<='C')||(a2[2]>'C'&&a4[2]>'C'))d=1;
    else d=0;
    if((a2[2]=='A'&&a4[2]=='B')||(a2[2]=='B'&&a4[2]=='C')||(a2[2]=='D'&&a4[2]=='E')||(a4[2]=='A'&&a2[2]=='B')||(a4[2]=='B'&&a2[2]=='C')||(a4[2]=='D'&&a2[2]=='E'))e=1;
    else e=0;
    }
    else b=0;
    cout<<a<<b<<d<<e;
    return 0;
}

