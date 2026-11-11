#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int m=0;
	char b;
	cin>>n;
	string s; 
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b;
		for(int j=m;j<=m+a[i];j++)
		{
			s[j]=b;
		}
		m+=a[i];
	}
	if(s[0]==s[s.size()])
	{
		cout<<"0";
	}
	if(n==1)
	{
		cout<<0;
	}
	if(n==2)
	{
		if(s[0]==s[1])
		{
			cout<<0;
		}
		else
		{
			cout<<1;
		}
	}	
	return 0;
}
