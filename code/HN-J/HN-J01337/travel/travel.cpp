#include <bits/stdc++.h>
using namespace std;
char a[10];
char b[10];
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
cin>>b[1]>>b[2]>>b[3]>>b[4]>>b[5];
if(a[1]==b[1]&&a[2]==b[2])
{
cout<<"1";
if(a[3]==b[3]&&a[4]==b[4])
{
cout<<"1";
if((a[5]<='C'&&b[5]<='C')||(a[5]>'C'&&b[5]>'C'))
{
cout<<"1";
int x=a[5],y=b[5];
if(abs(x-y)==1)
cout<<"1";
else
cout<<"0";
}
else
cout<<"00";
}
else
cout<<"000";
}
else
cout<<"0000";

   return 0;
}
