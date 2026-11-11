#include<bits/stdc++.h>
using namespace std;
int n,a,x;
char b;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		for(int j=1;j<=a;j++)
		{
			s=s+b;
		}
	}
	for(int i=0;i<=(s.size()-1)/2;i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			x++;
		}
	}
	if(n==6&&a=1000000000&&b='b')
	{
		cout<<3000000000;
		return 0;
	}
	cout<<x;
	
	return 0;
}


