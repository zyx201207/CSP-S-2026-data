#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int a,x;
string b,y;
cin>>a>>b>>x>>y;
if(a!=x)
{
cout<<"0000";
break;
}
else
{
cout<<1;
}
if(b[0]!=y[0]||b[1]!=y[1])
{
cout<<"000";
break;
}
else
{
cout<<1;
}
if((b[2]=='C'&&y[2]=='D')||(b[2]=='D'&&y[2]=='C'))
{
cout<<"00";
break;
}
else
{
cout<<1;
}
if((b[2]-1==y[2])||(b[2]==y[2]-1))
{
cout<<"0";
}
else
{
cout<<1;
}
return 0;
}
