#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    filopen("travel.in","r",stdin);
    filopen("travel.out","w",stdout);
    int r;
    string s;
    int x;
    string s1;
    cin>>r>>s>>x>>s1;
    if(r==x){
        cout <<1;
    }else{
        cout <<"0000";
        return 0;
    }
    if(s[0]*10+s[1]==s1[0]*10+s[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(s[2]=='A'||s[2]=='B'||s[2]=='C'&&s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
        cout<<1;
    }else if(s[2]=='D'||s[2]=='F'&&s1[2]=='F'||s1[2]=='D'){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(s[2]=='A'&&s1[2]=='B'||s[2]=='C'&&s1[2]=='B'||s[2]=='B'&&s1[2]=='A'||s[2]=='B'&&s1[2]=='C'||s[2]=='D'&&s1[2]=='F'||s[2]=='F'&&s1[2]=='D'){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
