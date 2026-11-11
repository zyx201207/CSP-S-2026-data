#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
char a;
string s,c,d;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x>>a;
		for(int j=0;j<x;j++)
		{
			s+=a;
		}
	}
	int l=s.size()/2;
	for(int i=0;i<l;i++)
	{
		c+=s[i];
	}
	for(int i=s.size()-1;i>l;i--)
	{
		d+=s[i];
	}
	for(int i=0;i<l;i++)
	{
		if(c[i]!=d[i])
		ans++;
	}
	cout<<ans;
}

