#include<bits/stdc++.h>
using namespace std;


int main(){
freopen("travel5.in","r",stdin);
freopen("travel5.out","w",stdout);

string a,b,a1,b1;
cin>>a>>b>>a1>>b1;
if(a==a1){
    cout<<"1";
}
else{
    cout<<"0";
}
if(a==a1 && (b[0]==b1[0] && b[1]==b1[1])){
    cout<<"1";
}
else{
    cout<<"0";
}
if(a==a1 && (b[0]==b1[0] && b[1]==b1[1]) && ((b[2]=='A'||b[2]=='B'||b[2]=='C' )&&( b1[2]=='A'||b1[2]=='B'||b1[2]=='C' ))||(( b[2]=='D'||b[2]=='F') && (b1[2]=='D'||b1[2]=='F'))){
    cout<<"1";
}
else{
    cout<<"0";
}
if(a==a1 && (b[0]==b1[0] && b[1]==b1[1]) && ((b[2]=='A'||b[2]=='B'||b[2]=='C' )&&( b1[2]=='A'||b1[2]=='B'||b1[2]=='C' ))||(( b[2]=='D'||b[2]=='F') && (b1[2]=='D'||b1[2]=='F'))){
    if(((b[2]+1==b1[2]) || (b[2]-1==b1[2])) || ((b[2]=='D'&&b1[2]=='F')||(b[2]=='F'&&b1[2]=='D'))){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
}
else{
    cout<<"0";
}



return 0;
}
