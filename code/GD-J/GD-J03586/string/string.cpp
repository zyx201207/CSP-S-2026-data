#include<bits/stdc++.h>
using namespace std;
int l;
bool cheak(string a)
{
	for(int i=0;i<l;i++)
	{
		if(i!=l-1-i)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string s;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long l=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		l+=x;
		string s1;
		cin>>s1;
		for(int i=0;i<x;i++)
		{
			s+=s1;
		}
	}
	long long ans=0;
	for(int i=l-1;i>=l/2;i--)
	{
		if(s[i]!=s[l-1-i])
		{
			ans++;
		}
	}
	cout<<ans;
 } 
