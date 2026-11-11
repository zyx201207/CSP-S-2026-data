#include<bits/stdc++.h>
using namespace std;
bool f1(char x,char y){
return (x<='C'&&y<='C')||(x>'C'&&y>'C');
}
bool f2(char x,char y){
if(x==65&&y==66) return 1;
if(x==66&&y==65) return 1;
if(x==66&&y==67) return 1;
if(x==67&&y==66) return 1;
if(x==68&&y==70) return 1;
if(x==70&&y==68) return 1;
return 0;
}
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
bool a=0,b=0,c=0,d=0;
cin>>c1>>s1>>c2>>s2;
if(c1==c2){
a = 1;
if(s1[0]==s2[0]&&s1[1]==s2[1]){
b = 1;
if(f1(s1[2],s2[2])){
c = 1;
d = f2(s1[2],s2[2]);
}
}
}
cout<<a<<b<<c<<d;
return 0;
}
