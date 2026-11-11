#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }
    bool a=0,b=0;
    if(s1[2]=='A'){
        a=0;
    }else if(s1[2]=='B'){
        a=0;
    }else if(s1[2]=='C'){
        a=0;
    }else if(s1[2]=='D'){
        a=1;
    }else{
        a=1;
    }
    if(s2[2]=='A'){
        b=0;
    }else if(s2[2]=='B'){
        b=0;
    }else if(s2[2]=='C'){
        b=0;
    }else if(s2[2]=='D'){
        b=1;
    }else{
        b=1;
    }
    if(a==b){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    bool c=0;
    if(s1[2]=='A'&&s2[2]=='B'){
        c=1;
    }else if(s1[2]=='B'&&s2[2]=='A'){
        c=1;
    }else if(s1[2]=='B'&&s2[2]=='C'){
        c=1;
    }else if(s1[2]=='C'&&s2[2]=='B'){
        c=1;
    }else if(s1[2]=='D'&&s2[2]=='F'){
        c=1;
    }else if(s1[2]=='F'&&s2[2]=='D'){
        c=1;
    }
    if(c==1){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
