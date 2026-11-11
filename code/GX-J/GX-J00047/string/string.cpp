#include<bits/stdc++.h>
using namespace std;
long long int a[1000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)
	cout<<"0";
	string s;
	string s1;
	for(int i=0;i<n;i++)
	{
		int m=0;
		cin>>m;
		cin>>s[i];
		for(int j=0;j<m;j++)
		s1[j]==s[i];
	}
	for(int i=0;i<s1.size();i++)
	{
		s[i]=s1[i];
		for(int j=0;j<s1.size();j++)
		{
			if(s[i]==s1[j])
			{
				a[i]++;
			}
		}
	}
	int x=0;
	for(int i=0;i<1000000;i++)
	{
		if(a[i]>x)
		x=a[i];
	}
	cout<<s1.size()-x;
	return 0;
}
