#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
char cs1,cs2;
int is1,is2;
int a=0,b=0,c=0;
int main(){
    cin>>c1>>s1>>c2>>s2;
    cs1=s1[2];cs2=s2[2];
    is1=s1[0]*10+s1[1];is2=s2[0]*10+s2[1];
    if(c1==c2){
        cout<<1;
        a=1;
    }
    else cout<<0;
    if(is1==is2&&a==1){
        cout<<1;
        b=1;
    }
    else cout<<0;
    if(b==1&&(((cs1=='A'||cs1=='B'||cs1=='C')&&(cs2=='A'||cs2=='B'||cs2=='C'))||((cs1=='D'||cs1=='F')&&(cs2=='D'||cs2=='F')))){
        cout<<1;
        c=1;
    }
    else cout<<0;
    if(c==1&&((cs1=='A'&&cs2=='B')||(cs1=='B'&&cs2=='A')||(cs1=='C'&&cs2=='B')||(cs1=='B'&&cs2=='C')||(cs1=='D'&&cs2=='F')||(cs1=='F'&&cs2=='D'))){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
