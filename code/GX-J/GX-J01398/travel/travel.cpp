#include<bits/stdc++.h>
using namespace std;
int main()
{
 freopen("travel.in","r",stdin);
 freopen("travel.out","w",stdout);
 char c1,s1,c2,s2,n,m;
 int S1,S2;
 cin>>c1>>s1>>c2>>s2;
 if(c1==c2){
    cout<<"1";
 }  else {
    cout<<"0";
 }
 S1=s1;
 S2=s2;
 if(S1==S2){
    cout<<"1";
 } else {
    cout<<"0";
}
 n=s1-S1;
 m=s2-S2;
 if((n=='A' && m=='B')||(n=='B' && m=='A'||'C')||(n=='c'&& m=='D'||'B')||(n=='D' && m=='F'||'C')||(n=='F' && m=='D')){
    cout<<"1";
 } else {
    cout<<"0";
 }
 if((n=='A' && m=='B'||'C')||(n=='B' && m=='A'||'C')||(n=='c'&& m=='A'||'B')||(n=='D' && m=='F')||(n=='F' && m=='D')){
    cout<<"1";
 } else {
    cout<<"0";
 }
 return 0;
}
