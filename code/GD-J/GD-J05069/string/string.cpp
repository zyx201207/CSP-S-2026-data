#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	int n,x,ans=0;
	char b;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x>>b;
		for(int j=0;j<x;j++)a+=b;
	}
	for(int i=0;i<=a.size()/2;i++)
	{
		if(a[i]!=a[a.size()-i-1])ans++;
	}
	cout<<ans;
	return 0;
} 
