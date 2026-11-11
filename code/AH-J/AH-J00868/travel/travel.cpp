#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r","stdin");
    freopen("travel.out","w","stdout");
    char c1[2],c2[2];
    char s1[3],s2[3];
    cin>>c1>>s1>>c2>>s2;
    int c=s1[2]-'0';
    int d=s2[2]-'0';
    int sum='C'-'0';
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[1]==s2[1]){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if(s1[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&s1[2]=='F'){
        cout<<"1";
    }
    else if(s1[2]=='A'&&s2[2]=='B'||s2[2]=='A'&&s1[2]=='B'){
        cout<<"1";
    }
    else if(s1[2]=='B'&&s2[2]=='C'||s2[2]=='B'&&s1[2]=='C'){
        cout<<"1";
    }
    else if(s1[2]=='A'&&s2[2]=='C'||s2[2]=='A'&&s1[2]=='C'){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(s1[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&s1[2]=='F'){
        cout<<"1";
    }
    else if(s1[2]=='A'&&s2[2]=='B'||s2[2]=='A'&&s1[2]=='B'){
        cout<<"1";
    }
    else if(s1[2]=='B'&&s2[2]=='C'||s2[2]=='B'&&s1[2]=='C'){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
