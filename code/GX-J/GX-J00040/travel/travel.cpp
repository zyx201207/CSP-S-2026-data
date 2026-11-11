#include <bits/stdc++.h>
using namespace std;
string a,b,c,d,e;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>b>>c>>d;
if(a==c){
e[0]='1';
}
else{
e[0]='0';
}
if(b[0]==d[0]&&b[1]==d[1]){
e[1]='1';
}
else{
e[1]='0';
}
if(b[2]!=d[2]+1 || b[2]!=d[2]-1||b[2]==d[2]-2||b[2]==d[2]-2||b[2]==d[2]+3||b[2]==d[2]-3||b[2]==d[2]-4||b[2]==d[2]+4){
e[2]='0';
}
else{
e[2]='1';}
if(b[2]==d[2]-1||d[2]==b[2]-1){
e[3]='1';
}
else{
e[3]='0';
}
cout<<e;
return 0;
}
