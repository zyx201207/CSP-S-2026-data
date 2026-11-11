#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,sum;
string s,hw="";
int main()
{	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		int a;
		char c;
		cin>>a>>c;
		for(int j=1; j<=a; j++)
			s+=c;
	}
	int len=s.size();
	if(len%2==0)
	{
		for(int i=0; i<=len/2-1; i++)
			hw+=s[i];
		for(int i=len/2-1; i>=0; i--)
			hw+=s[i];
		for(int i=len/2; i<=len-1; i++)
			if(s[i]!=hw[i])
				sum++;
	}
	else
	{
		for(int i=0; i<=(len-1)/2; i++)
			hw+=s[i];
		for(int i=(len-1)/2-1; i>=0; i--)
			hw+=s[i];
		for(int i=(len-1)/2+1; i<=len-1; i++)
			if(s[i]!=hw[i])
				sum++;
	}
	cout<<sum;
	return 0;
}
