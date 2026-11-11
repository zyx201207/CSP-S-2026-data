#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
int a,c;
string b,d;
cin>>a>>b>>c>>d;
if(a==c){
cout<<1;
if(b[0]==d[0] && b[1]==d[1]){
cout<<1;
int o,l;
if(b[2]=='A'){
o=1;
}
if(b[2]=='B'){
o=2;
}
if(b[2]=='C'){
o=3;
}
if(b[2]=='D'){
o=4;
}
if(b[2]=='E'){
o=5;
}
if(d[2]=='A'){
l=1;
}
if(d[2]=='B'){
l=2;
}
if(d[2]=='C'){
l=3;
}
if(d[2]=='D'){
l=4;
}
if(d[2]=='E'){
l=5;
}
int p=0;
if(o>=1 && o<=3 && l>=1 && l<=3 || o>=4 && o<=5 && l>=4 && l<=5){
cout<<1;
p=1;
if(p==1 && max(o,l)-min(o,l)==1){
cout<<1;
}
else{
cout<<0;
}
}
else{
cout<<0<<0;
}

}
else{
cout<<0<<0<<0;
}
}
else{
cout<<0<<0<<0<<0;
}

return 0;
}
