#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int c11,c22,s11,s22,z1,z2;
int q1,q2,q3,q4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    c11=(c1[0]-'0')*10+c1[1]-'0';
    c22=(c2[0]-'0')*10+c2[1]-'0';
    if(c11==c22)q1=1;
    else{
        cout<<"0"<<"0"<<"0"<<"0";
        return 0;
    }
    s11=(s1[0]-'0')*10+s1[1]-'0';
    s22=(s2[0]-'0')*10+s2[1]-'0';
    if(s11==s22)q2=1;
    else{
        cout<<"1"<<"0"<<"0"<<"0";
        return 0;
    }
    z1=s1[2]-'A'+1;
    z2=s2[2]-'A'+1;
    if((z1<=3&&z2<=3)||(z1>3&&z2>3))q3=1;
    else{
        cout<<"1"<<"1"<<"0"<<"0";
        return 0;
   
    if(((z1+1)==z2)||((z1-1)==z2)||((z1==4)&&(z2==6)))cout<<"1"<<"1"<<"1"<<"1";
    else cout<<"1"<<"1"<<"1"<<"0";
return 0;
}