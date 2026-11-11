#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool flag=1;
    if(c1==c2&&c1!="01"&&c1!="16"&&flag){
        cout<<"1";
    }
    else{
        cout<<"0";
        flag=false;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag){
        cout<<"1";
    }
    else{
        cout<<"0";
        flag=false;
    }
    if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&s1[2]!=s2[2]&&flag){
        cout<<"1";
    }
    else{
        cout<<"0";
        flag=false;
    }
    if(s1[2]=='A'&&s2[2]=='B'&&flag){
        cout<<"1";
    }
    else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')&&flag){
        cout<<"1";
    }
    else if(s1[2]=='C'&&s2[2]=='B'&&flag){
        cout<<"1";
    }
    else if(s1[2]=='D'&&s2[2]=='E'&&flag){
        cout<<"1";
    }
    else if(s1[2]=='E'&&s2[2]=='D'&&flag){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
