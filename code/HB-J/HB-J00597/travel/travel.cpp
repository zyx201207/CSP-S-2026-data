#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string s,c,a,b;
cin>>s>>c>>a>>b;
if(s==a)
{
cout<<"1";
if(c[0]==b[0]&&c[1]==b[1])
{
cout<<"1";
if(((c[2]>='A'&&c[2]<='C')&&(b[2]>='A'&&b[2]<='C'))||((c[2]=='D'||c[2]=='F')&&(b[2]=='D'||b[2]=='F')))
{
cout<<"1";
if(c[2]-'a'-1==b[2]||c[2]-'a'+1==b[2])
{
cout<<"1";
}
else
{
cout<<"0";
}
}
else
{
cout<<"00";
}
}
else
{
cout<<"000";
}
}
else
{
cout<<"0000";
}
return 0;
}
