#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int z=0,x=0,v=0,n=0;
    cin>>a>>b>>c>>d;
    if(a==c){
        z=1;
    }
    else{
        cout<<0000;
        return 0;
    }
    if(b[0]==d[0]){
        x=1;
    }
    else{
        cout<<1100;
        return 0;
    }
    if(b[1]==d[1]){
        v=1;
    }
    else{
        cout<<1110;
        return 0;
    }
    if(b[2]=='A'&&d[2]=="B"){
        n=1;
    }
    else if(b[2]=="B"&&d[2]=="A"){
        n=1;
    }
    else if(b[2]=="B"&&d[2]=="C"){
        n=1;
    }
    else if(b[2]=="C"&&d[2]=="B"){
        n=1;
    }
    else if(b[2]=="D"&&d[2]=="F"){
        n=1;
    }
    else if(b[2]=="F"&&d[2]=="D"){
        n=1;
    }
    if (n==1){
        cout<<1111;
        return 0;
    }
