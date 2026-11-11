#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,n;
	cin>>c1>>s1>>c2>>s2>>n;
	if(c1!=c2)
	{
		cout<<"0000"<<" ";
		return 0;
	}
	else
	{
		cout<<"1";
	}
	if(s1==n&&s2==n)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(s1=="F"&&s2=="D")
	{
		cout<<"1";
	}
	else if(s1=="D"&&s2=="F")
	{
		cout<<"1";
	}
if(s1=="A"&&s2=="B")
{
	cout<<1;
}
if(s1=="B"||s2=="A"||s2=="C")
{
	cout<<1;
}
if(s1=="C"&&s2=="B")
{
	cout<<1;
}
if(s2=="B"||s1=="A"||s1=="C")
{
	cout<<1;
}
	return 0;
}
