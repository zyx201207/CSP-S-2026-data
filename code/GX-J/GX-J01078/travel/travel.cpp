#include<bits/stdc++.h>
using namespace std;
string s[20],c[20],ss,sss;
int k=0;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
for(int i=1;i<=2;i++)
{
cin>>c[i]>>s[i];
}
if(c[1]==c[2])
{
cout<<1;
ss=s[1];
sss=s[2];
for(int i=0;i<=1;i++)
{
if(ss[i]==sss[i])
{
k++;
}
}
if(k==2)
{
cout<<1;
if(ss[2]=='D'&&sss[2]=='F'||ss[2]=='F'&&sss[2]=='D'||ss[2]=='A'&&sss[2]=='B'||ss[2]=='B'&&sss[2]=='A'||ss[2]=='B'&&sss[2]=='C'||ss[2]=='C'&&sss[2]=='B'||ss[2]=='A'&&sss[2]=='C'||ss[2]=='C'&&sss[2]=='A')
{
cout<<1;
if(ss[2]=='D'&&sss[2]=='F'||ss[2]=='F'&&sss[2]=='D'||ss[2]=='A'&&sss[2]=='B'||ss[2]=='B'&&sss[2]=='A'||ss[2]=='B'&&sss[2]=='C'||ss[2]=='C'&&sss[2]=='B')
{
cout<<1;
return 0;
}
else
{
cout<<0;
return 0;
}
}
else
{
cout<<00;
return 0;
}
}
else
{
cout<<000;
return 0;
}
}
else
{
cout<<0000;
return 0;
}
return 0;
}
