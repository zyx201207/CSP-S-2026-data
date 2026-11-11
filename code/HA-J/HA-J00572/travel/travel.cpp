#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
freopen,"travel.in" "r",stdin;
freopen,"travel.out" "w" ,stdout;
int c1,c2,A,B,C,D,F;	
int s1,s2;
cin>>c1>>s1>>c2>>s2;
A=1;
B=2;
C=3;
D=5;
F=6;
if(c1=c2)
{
cout<<0;
return 0;	
}
else
{
cout<<1;	
}
if(s1/10==s2/10)
{
cout<<1;	
}
else
{
cout<<0;	
}
if(s1/10==s2/10&&s1%10<=3&&s2%10<=3)
{
cout<<1;	
}
else
{
cout<<0;	
}
if(s1%10==s2%10+1||s1%10==s2%10-1)
{
cout<<1;	
}
else
{
cout<<0;	
}
return 0;	
}
