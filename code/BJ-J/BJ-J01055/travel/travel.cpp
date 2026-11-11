#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    
    freopen("travel","r","in");
    freopen("travel","w","out");
    cin>>s1>>s2>>s3>>s4;
    if(s1[0]==s3[0]&&s1[1]==s3[1]){
        cout<<"1";
    }
    if(s1[0]!=s3[0]||s1[1]!=s3[1]){
        cout<<"0000";
        return 0;
    }
    if(s2[1]==s4[1]){
        cout<<"1";
    }
    if(s2[1]!=s4[1]){
        cout<<"000";
        return 0;
    }
    if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')){
        cout<<"1";
    }
    if((s2[2]=='D'&&s4[2]=='F')||(s4[2]=='D'&&s2[2]=='F')){
        cout<<"1";
    }
    if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='D'||s4[2]=='F')){
        cout<<"00";
        return 0;
    }
    if((s2[2]=='D'&&s4[2]!='F')||(s4[2]=='D'&&s2[2]!='F')){
        cout<<"00";
        return 0;
    }
    if((s2[2]==s4[2]+1&&s4[2]!='C')||(s2[2]==s4[2]-1&&s4[2]!='D')){
        cout<<"1";
        return 0;
    }
    if((s2[2]==s4[2]+1&&s4[2]=='C')||(s2[2]==s4[2]-1&&s4[2]=='D')){
        cout<<"0";
        return 0;
    }
    if((s2[2]!=s4[2]+1)&&(s2[2]!=s4[2]-1)){
        cout<<"0";
        return 0;
    }
    return 0;
}
