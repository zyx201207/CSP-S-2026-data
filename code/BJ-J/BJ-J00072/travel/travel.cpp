#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) cout<<"0000";
    else{
        char a=s1[0],b=s1[1],c=s2[0],d=s2[1];
        if(a!=c||b!=d) cout<<"1000";
        else{
            char e=s1[2],f=s2[2];
            if(((e=='A'||e=='B'||e=='C')&&(f=='D'||f=='F'))||((f=='A'||f=='B'||f=='C')&&(e=='D'||e=='F'))) cout<<"1100";
            else{
                if((e=='A'&&f!='B')||(e=='B'&&(f!='A'&&f!='C'))||(e=='C'&&f!='B')||(e=='D'&&f=='F')||(e=='F'&&f=='D')) cout<<"1110";
                else cout<<"1111";
            }
        }
    }
    return 0;
}
