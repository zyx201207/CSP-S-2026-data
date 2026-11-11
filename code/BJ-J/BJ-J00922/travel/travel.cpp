#include<bits/stdc++.h>
using namespace std;
bool f;
int a,b,c,d;
char s1,s2;

void o(bool g){
if(!g){
cout<<0;
return;
}else if(s2=='A'&&s1=='C'){
cout<<0;
f=false;
return;
}
cout<<1;
return;
}

void l(bool g){
if(!g){
cout<<0;
return;
}else if(s1>='D'&&s2>='D'){
cout<<1;
return;
}else if(s2<='C'&&s1<='C'){
cout<<1;
return;
}
cout<<0;
f=false;
return;
}

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>b>>s1>>c>>d>>s2;
if(a==c){
cout<<1;
f=true;
}
else cout<<0;
if(f&&b==d) cout<<1;
else{
cout<<0;
f=false;
}
l(f);
o(f);
return 0;
}
