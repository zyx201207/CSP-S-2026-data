#include<bits/stdc++.h>
using namespace std;

string aa(string s,int a,char b)
{
	for(int i=1;i<=a;i++)
	s=s+b;
    
    return s;
 } 

string hh(string s)
{
	int i,h;
	string a="";
	h=s.size();
	for(i=0;i<h;i++)
	a=s[i]+a;
	
	return a;
}

long long w=0;
	long long n,a,i;
	char c;
	string s="",z;

int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	
	for(i=1;i<=n;i++)
	{
		cin>>a>>c;
		s=aa(s,a,c);
		w=w+a;
	}
	z=hh(s);
	
	if(z==s)
	{
		cout<<0;
		return 0;
	}
	else
	{
		cout<<w/2;
	}
	return 0;
}
