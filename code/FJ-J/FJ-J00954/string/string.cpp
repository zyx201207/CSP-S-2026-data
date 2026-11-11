#include<bits/stdc++.h> 
using namespace std;
string s="0";
int n;
int hw(string x)
{
	int l=s.size()-1;
	long long ans=0;
	for(int i=1;i<=l;i++)
	{
		if(s[i]!=s[l+1-i])
		{
			ans++;
		}
	}
	return ans/2;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	cout<<hw(s);
	return 0;
}
