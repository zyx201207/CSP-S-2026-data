#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,b,c,d,s,j;
int ans,cnt;
char o,n;
cin>>a>>b>>c>>d;
if(a==c)
{
	cout<<"1";
}
else
{
	cout<<"0000";
	return 0;
}
s=b.substr(0,2);
j=d.substr(0,2);
if(s==j)
{
	cout<<"1";
 } 
 else
 {
 	cout<<"000";
 	return 0;
 }
 s=b.substr(2,1);
 j=d.substr(2,1);
 if(s=="A"||s=="B"||s=="C")
 {
 	cnt=1;
 }
 else
 {
 cnt=0;
}
if(j=="A"||j=="B"||j=="C")
 {
 	ans=1;
 }
 else
 {
 ans=0;
}
if(ans==cnt)
{
	cout<<"1";
}
else
{
	cout<<"00";
	return 0;
}
if(ans==1)	 
{
	if(s=="B"||j=="B")
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
	cout<<"1";
}
	
return 0;
}

