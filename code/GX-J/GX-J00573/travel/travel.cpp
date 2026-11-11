#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,b,c,d;
cin>>a>>b>>c>>d;
if(a==c){
    cout<<1;
}
else{
    cout<<"0000";
    return 0;
}
string n,m;
n=b[0]+b[1];
m=d[0]+d[1];
if(n==m){
    cout<<1;
}
else{

    cout<<"000";
return 0;
}
char x,y;
x=b[2];
y=d[2];
if((x>='A'&&x<='C')&&(y>='A'&&y<='C')){
    cout<<1;
    if(abs(x-y)==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
}
else if((x>='D'&&x<='F')&&(y>='D'&&y<='F')){
    cout<<1;
    if(abs(x-y)==2){
        cout<<1;
    }
    else{
        cout<<0;
    }
}
else{
    cout<<"00";
}

return 0;}
