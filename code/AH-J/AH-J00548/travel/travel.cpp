#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1,s2;
int main(){
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;

if(c1==c2){
cout<<"1";
}else{
cout<<"0";
}
if(s1/100==s2/100){
cout<<"1";
}else{
cout<<"0";
}
if(s1-s2==1||s2-s1==1){
cout<<"11";
}else{
cout<<"00";
}
return 0;
}
