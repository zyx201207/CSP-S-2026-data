#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a=0;
	cin>>n;
	int x[n];
	string y;
	for(int i=0;i<n;i++)
	cin>>x[i]>>y[i];
	string s;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<x[i];j++)
		s[j]=y[j];
	}
	string t;
	for(int i=0;i<s.size()/2+1;i++)
	t[i]=s[i];
	for(int i=0;i<s.size()/2+1;i++)
	{
		if(t[i]!=s[i+s.size()/2])
		a=a+1;
	}
	cout<<a<<endl;
	return 0;
}
