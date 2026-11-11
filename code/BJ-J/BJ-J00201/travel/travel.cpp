#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,b,c,d;
cin>>a>>b>>c>>d;
if(a==c)
cout<<1;
else{
cout<<0<<0<<0<<0;
return 0;
}
if(b[0]+b[1]==d[0]+d[1])
cout<<1;
else{
cout<<0<<0<<0;
return 0;
}
if(b[2]>'c'&&d[2]>'c'||b[2]<='c'&&d[2]<='c')
cout<<1;
else{
cout<<0<<0;
return 0;
}
if((b[2]+1==int(d[2]))||(c[2]+1==int(d[2])))
cout<<1;
else{
cout<<0;
}
return 0;
}
