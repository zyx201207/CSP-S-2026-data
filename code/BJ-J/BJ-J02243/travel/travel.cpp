#include<bita/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
int a1,a2;
char b1,b2;
a1=s1;
a2=s2;
b1=s2;
b2=s2;
if(c1==c2){
    cout<<1;
}else{
    cout<<0;
}
if(a1=a2){
   cout<<1; 
}else{
    cout<<0;
}
if(b1='A'|| b1='B'|| b1='C'&& b2='A'|| b2='B'|| b2='C'&&a1!=a2){
    cout<<1;
}else if(b1='D'|| b1='F'&& b2='D'|| b2='F'&&a1!=a2){

cout<<1;
}else{
cout<<0;
}
if(b1=b2){
    cout<<1;
}else{
    cout<<0;
}

return 0;
}
