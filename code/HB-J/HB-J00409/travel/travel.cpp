#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
char x,y;
x=s1[2];
s1[2]=0;
y=s2[2];
s2[2]=0;
if(c1==c2){
    cout<<"1";
    if(s1==s2){
        cout<<"1";
        if(((x=='D'||x=='F')&&(y=='D'||y=='F'))||((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C'))){
        cout<<"1";
        if((x=='A'&&y=='B')||(x=='B'&&y=='C')||(x=='C'&&y=='B')||(x=='B'&&y=='A')||(x=='D'&&y=='F')||(x=='F'&&y=='D')){
            cout<<"1";
            }else{cout<<"0";}
        }else{cout<<"0"<<"0";}
    }else{cout<<"0"<<"0"<<"0";}
}else{cout<<"0"<<"0"<<"0"<<"0";}
return 0;
}
