#include<bits/stdc++.h>
using namespace std;
string c,s,c1,s1;
bool q1,q2,q3,q4;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c>>s>>c1>>s1;
if(c[0]!=c1[0]||c[1]!=c1[1]){
    cout<<"0000";
    return 0;
}
if(c[0]==c1[0]&&c[1]==c1[1]){
    q1=true;
    if(s[0]==s1[0]&&s[1]==s1[1]){
        q2=true;
        if(s[2]>='A'&&s[2]<='C'){
            if(s1[2]>='A'&&s1[2]<='C'&&s1[2]!=s[2]){
                q3=true;
                 if(s[2]+1==s1[2]||s[2]-1==s1[2]){
    q4=true;
 }
            }
        }
        if(s[2]>='D'&&s[2]<='F'&&s[2]!='E'){
            if(s1[2]>='D'&&s1[2]<='F'&&s1[2]!=s[2]&&s1[2]!='E'){
                q3=true;
                 if(s[2]+1==s1[2]||s[2]-1==s1[2]){
    q4=true;
 }
            }
        }
    }
}
cout<<"1";
if(q2){
    cout<<"1";
}
else{
    cout<<"0"<<"0"<<"0";
}
if(q3){
    cout<<"1";
}
else{
    cout<<"0"<<"0";
}
if(q4){
    cout<<"1";
}
else{
    cout<<"0";
}
return 0;
}