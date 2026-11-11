#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

bool x;
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
if(c1!="01"&&c2!="01"&&c1!="16"&&c2!="16"){
if(c1==c2)
cout<<1;
x=1;
}

else{
cout<<0;
x=0;}

string c=char(s1[0])+char(s1[1]);
string d=char(s2[0])+char(s2[1]);
if(c==d&&x==1){
    cout<<1;
    }
else{
cout<<0;
x=0;
}

int a=s1[2];
int b=s2[2];

if(x==1){
if(abs(int(s1[2]-s2[2]))<=2&&min(a,b)!=68){
cout<<1;
}
}
else{
cout<<0;
x=0;
}

if(x==1&&abs(a-b)==1)
cout<<1;
else
cout<<0;

return 0;}
