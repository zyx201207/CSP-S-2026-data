#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,b,c,d;
cin>>a;
cin>>b;
cin>>c;
cin>>d;
while (1){
if(a[0]==c[0] and a[1]==c[1]){
    cout<<1;
}else{
    cout<<0;
    cout<<0;
    cout<<0;
    cout<<0;
    break;
}
if(b[0]==d[0] and b[1]==d[1]){
    cout<<1;
}else{
    cout<<0;
    cout<<0;
    cout<<0;
    break;
}
if((b[2]<='C' and d[2]<='C') or (b[2]>'C' and d[2]>'C') ){
    cout<<1;
}else{
    cout<<0;
    cout<<0;
    break;
}
if(int(b[2]-d[2])<=1){
    cout<<1;
    break;
}else{
    cout<<0;
    break;
}
}
return 0;
}
