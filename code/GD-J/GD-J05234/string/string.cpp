#include<bits/stdc++.h> 
using namespace std;
int n,s,x,t;
string a;
char b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>b;
		t+=x;
		for(int j=1;j<=x;j++)
		{
			a+=b;
		}
	}
	for(int i=0;i<=t/2;i++)
	{
		if(a[i]!=a[t-i-1])
		{
			s++;
		}
	}
	cout<<s;
	return 0;
} 
