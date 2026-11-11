#include<bits/stdc++.h>
using namespace std;//68
string s,ss;
int main()
{
	//freopen("string6.in","r",stdin);
	//freopen("string6.out","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int rp=114514;	
	int n,a,ans=0;
	char c;
	cin>>n; 
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		for(int j=0;j<a;j++)
		{
			s+=c;
		}
	}
	int t=s.size();
	for(int i=0;i<t;i++)
	{
		ss+=s[t-i-1];
	}
	for(int i=0;i<t/2;i++)
	{
		if(s[i]!=ss[i]) ans++;
	}
	cout<<ans;
	return 0;
 } //初一9A要饿晕！！！饿不思蜀！！！ 
