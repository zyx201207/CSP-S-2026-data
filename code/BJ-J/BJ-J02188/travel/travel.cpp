#include<bits/stdC++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int c1,c2,z=0,x=0,c=0,v=0,s1,s2;
cin>>c1>>s1>>c2>>s2;
if(c1==c2){
z=1;
if(s1+1==s2||s1+2==s2||s1+3==s2||s1+4==s2||s1+5==s2||s2+1==s1||s2+2==s1||s2+3==s1||s1+4==s2||s1+5==s1){
x=1;
if(s1+1==s2||s1-1==s2){
c=1;
}}}
cout<<z<<x<<c<<v;
return 0;
}
