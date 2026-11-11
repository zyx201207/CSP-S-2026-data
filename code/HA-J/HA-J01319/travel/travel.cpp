#include<bits/stdc++.h>
using namespace std;
long long a,b;
string c,d;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>c>>b>>d;
if(a==b){
cout<<"1";
}
else{
cout<<"0000";
return 0;
}
c=' '+c;
d=' '+d;
int h1,h2;
h1=(int)(c[1]-'0')*10+(int)(c[2]-'0');
h2=(int)(d[1]-'0')*10+(int)(d[2]-'0');
if(h1==h2){
cout<<"1";
}
else{
cout<<"000";
return 0;
}
int z1,z2;
z1=int(c[3])-64;
z2=int(d[3])-64;
if(z1>=1&&z1<=3&&z2>=1&&z2<=3){
cout<<"1";
if(z1+1==z2||z1+2==z2||z2-1==z1||z2-2==z1){
cout<<1;
}
else{
cout<<"0";
}
}
else if((z1==4&&z2==6)||(z2==4&&z1==6)){
cout<<"11";
}
else{
cout<<"00";
}
return 0;	
}
