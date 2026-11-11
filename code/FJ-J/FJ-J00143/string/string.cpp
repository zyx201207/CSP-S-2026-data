#include<iostream>
#include<string>
#include<cmath>
#define int long long
using namespace std;

int f(string s)
{
	string k="";
	for(int i=s.size()-1;i>=0;i--)
	{
		k+=s[i];
	}
	int sum=0;
	for(int i=0;i<s.size();i++)
	{
		if(k[i]!=s[i])
			sum++;
	}
	return sum;
}

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		while(a--)
		{
			s+=c;
		}
	}
	cout<<f(s)/2;
}
