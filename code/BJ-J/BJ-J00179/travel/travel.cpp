#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s>>s1>>s2>>s3;
    bool f=(s==s2),f1=f&&(s1[0]==s3[0]&&s1[1]==s3[1]),f2=f1,f3;
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')if(s3[2]=='D'||s3[2]=='F')f2=0;
    if(s1[2]=='D'||s1[2]=='F')if(s3[2]=='A'||s3[2]=='B'||s3[2]=='C')f2=0;
    f3=f2;
    if(s1[2]=='A'&&(s3[2]!='B'))f3=0;
    if(s1[2]=='B'&&(s3[2]!='A'))f3=0;
    if(s1[2]=='C'&&(s3[2]!='B'))f3=0;
    if(s1[2]=='D'&&(s3[2]!='F'))f3=0;
    if(s1[2]=='F'&&(s3[2]!='D'))f3=0;
    cout<<f<<f1<<f2<<f3;
    return 0;
}