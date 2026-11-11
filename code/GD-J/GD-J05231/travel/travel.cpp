#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int check1(string x,string y)
{
	return x==y;
}
int check2(string x,string y)
{
	for(int i=0;i<2;i++)
	{
		if(x[i]!=y[i])return 0;
	}
	return 1;
}
int check3(string x,string y)
{
	if(x[2]=='A')
	{
		return (y[2]=='B' or y[2]=='C');
	}
	if(x[2]=='B')
	{
		return (y[2]=='A' or y[2]=='C');
	}
	if(x[2]=='C')
	{
		return (y[2]=='B' or y[2]=='A');
	}
	if(x[2]=='D')
	{
		return (y[2]=='F');
	}
	if(x[2]=='F')
	{
		return (y[2]=='D');
	}
	return 0;
}
int check4(string x,string y)
{
	if(x[2]=='A')
	{
		return (y[2]=='B');
	}
	if(x[2]=='B')
	{
		return (y[2]=='A' or y[2]=='C');
	}
	if(x[2]=='C')
	{
		return (y[2]=='B');
	}
	if(x[2]=='D')
	{
		return (y[2]=='F');
	}
	if(x[2]=='F')
	{
		return (y[2]=='D');
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	cout<<check1(c1,c2);
	cout<<(check1(c1,c2) and check2(s1,s2));
	cout<<(check1(c1,c2) and check2(s1,s2) and check3(s1,s2));
	cout<<(check1(c1,c2) and check2(s1,s2) and check3(s1,s2) and check4(s1,s2));
	return 0;
} 
