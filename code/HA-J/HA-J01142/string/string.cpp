#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int huiwen(const string &a)
{
	int len=a.length();
	int ans=0;
	for(int i=0;i<len/2;i++)
	{
		if(a[i]!=a[len-i-1])
		{
			//cout<<a[i]<<"!="<<" "<<a[len-i-1]<<endl;
			ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;	
	long long x;
	char t;
	int j=0;
	while(n--)
	{
		cin>>x>>t;		
		for(int i=j;i<x+j;i++)
		{
			s+=t;
		}
		j+=x;
	}
	cout<<huiwen(s);
	return 0;
}
