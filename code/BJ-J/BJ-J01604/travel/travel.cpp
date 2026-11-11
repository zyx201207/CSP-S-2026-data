#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","s",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    char s1[4],s2[4];
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    if(s1[0]!=s2[0]){
        cout<<"000";
        return 0;
    }
    if(s1[1]!=s2[1]){
        cout<<"000";
        return 0;
    }
    cout<<"1";
    int a,b;
    if(s1[2]=='A'){
        a=1;
    }
    if(s1[2]=='B'){
        a=2;
    }
    if(s1[2]=='C'){
        a=3;
    }
    if(s1[2]=='D'){
        a=4;
    }
    if(s1[2]=='F'){
        a=5;
    }
    if(s2[2]=='A'){
        b=1;
    }
    if(s2[2]=='B'){
        b=2;
    }
    if(s2[2]=='C'){
        b=3;
    }
    if(s2[2]=='D'){
        b=4;
    }
    if(s2[2]=='F'){
        b=5;
    }
    if((a<=3&&b<=3)||(a>3&&b>3)){
        cout<<"1";
        if(a+1==b||a-1==b){
            cout<<"1";
            return 0;
        }
        else {
            cout<<"0";
            return 0;
        }
    }
    else{
        cout<<"00";
        return 0;
    }
    return 0;
}
