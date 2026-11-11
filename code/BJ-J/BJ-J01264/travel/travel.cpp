#include<bits/stdc++.h>
using namepsace std;
int main()
{
freopen("travel.in","r",stdin)
freopen("travel.out","w",stdout)


int n,m,cnt=0;
cin>>n;
char a[3];
char b[3];


for(int i=0;i<3;i++)
{
cin>>a[i];
}
cin>>m;
for(int i=0;i<3;i++)
{
cin>>b[i];
}


if(n!=m)
{
cout<<"0000";
return 0;
}
else
{
cout<<"1";
}


for(int i=1;i<3;i++)
{
if('a[i]'=='b[i]')
{
cnt++;
}
}
if(cnt==2)
{
cout<<"1";
}
else
{
cout<<"000";
return 0;

if(a[3]=='A'||b[3]!='B'  ||  a[3]=='B'||b[3]!='A'||b[3]!='C'  ||  a[3]=='C'||b[3]!='B'||   a[3]=='D'||b[3]!='F'||  a[3]=='F'||b[3]!='D')
{
cout<<"00";
return 0;
}
else
{
cout<<"1";
}

if(a[3]=='A'&&b[3]=='B'||a[3]=='B'&&b[3]=='A'||a[3]=='B'&&b[3]=='C'||a[3]=='C'&&b[3]=='B'||a[3]=='D'&&b[3]=='F'||a[3]=='F'&&b[3]=='D')
{
cout<<"1";
}
else
{
cout<<"0";
return 0;
}

return 0;

}




}
