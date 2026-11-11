#include<bits/stdc++.h>
using namespace std;
string s="";

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int n;
	long long m=0;
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	 } 
	for(int i=1;i<=n;i++)
	{
		long long a;
		cin>>a;
		string b;
		cin>>b;
		for(int j=1;j<=a/10;j++)s=s+b+b+b+b+b+b+b+b+b+b;
		for(int j=1;j<=a%10;j++)s=s+b;
	}
	for(int i=0;i<=s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])m++;
	}
	cout<<m;
	return 0;
 } 
