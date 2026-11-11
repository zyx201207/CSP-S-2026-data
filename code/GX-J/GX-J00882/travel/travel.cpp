#include <bits/stdc++.h>
using namespace std;
int mian(){
freopen("travel.in","r",stdin);
freopen("travel,out","w",stdout);
string a,b[5],c,d[5];
int e=0,k=0,l=0;
cin>>a;
for(int i=0;i<=2;i++)
    cin>>b[i];
cin>>c;
for(int r=0;r<=2;r++)
    cin>>d[r];
if(a==c)
cout<<1;
for(int g=0;g<=1;g++){
    if(b[g]==d[g])
        e=1;
    else
        e=0;
}
cout<<e;
if((b[2]=="A"||b[2]=="D"||b[2]=="C")||(d[2]=="A"||d[2]=="D"||d[2]=="C")){
  l=1;
  cout<<l;
}
cout<<l;
if((b[2]=="A"&&d[2]=="B")||(d[2]=="A"&&b[2]=="B"))
    k=1;
if((b[2]=="D"&&d[2]=="F")||(d[2]=="F"&&b[2]=="D"))
    k=1;
cout<<k;

return 0;
}
