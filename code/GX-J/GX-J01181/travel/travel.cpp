#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in",stin);
freopen("travel.ans",stont);
string c1,s1,c2,s2,j;
cin>>c1>>s1>>c2>>s2;
j='0000';
if(c1==c2){
    j[0]='1';
    if(c1[0]==c2[0] && c1[1]==c2[1]){
        j[1]='1';
        if((s1[2]=='A'||s1[2]=='C'||s1[2]=='B')&&|(s2[2]=='A'||s2[2]=='C'||s2[2]=='B')){
            j[2]='1';
        }
        if((s1[2]=='F'||s1[2]=='D')&&|(s2[2]=='F'||s2[2]=='D')){
            j[2]='1';
        }
    }
    if((s1[2]=='A'||s1[2]=='C')&&s2[2]=='B'){
        j[2]='1';
    }
    if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
        j[2]='1';
    }
    if(s1[2]=='F'&&s2[2]=='D'){
        j[2]='1';
    }
    if(s1[2]=='D'&&s2[2]=='F'){
        j[2]='1';
    }
}
cout<<j;
return 0;
}
