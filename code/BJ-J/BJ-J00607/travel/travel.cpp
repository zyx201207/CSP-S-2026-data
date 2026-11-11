#include <bits/stdc++.h>
using namespace std;

int main (){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int a,c,n,m;
char x,y;
string b,d;
cin>>a>>b>>c>>d;
if(a==b){
    cout <<1;
}else{
cout<<0000;
    return 0;
}m=(b/100);n=int(b/100);m=int(d/100);x=char(b%100);y=char(d%100);
if(m==n){
    cout<<1;
}else{
    cout<<0;
}if(x=='E!'!)&(x=='F'!)&&(y=='E'!)&&(y=='F'!)){
    cout<<1;
}else if((x=='E')||(x=='F')&&(y=='F')||(y=='E')){
    cout<<1;
}else{
    cout<<0;
}if(x=='B'&&(y=='B')||(y=='C')){
    cout<<1;
}else if(y=='B'&&(x=='B')||(x=='C')){
    cout<<1;
}else if(y=='E'&&x=='F'){
    cout<<1;
}else if(y=='F'&&x=='E'){
    cout<<1;
    }else{cout <<0;
    }return 0;}
    
