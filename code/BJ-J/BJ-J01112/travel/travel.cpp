#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool a=false,b=false,c=false,d=false;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a=true;
    }if(s1[0]==s2[0]&&s1[1]==s2[1]&&a){
        b=true;
    }if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))&&b){
        c=true;
    }if(((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')||abs(s1[2]-s2[2])==1)&&c){
        d=true;
    }
    if(a){
        cout<<1;
    }else{
        cout<<0;
    }if(b){
        cout<<1;
    }else{
        cout<<0;
    }if(c){
        cout<<1;
    }else{
        cout<<0;
    }if(d){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}