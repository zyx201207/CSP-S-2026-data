#include<bits/stdc++.h>
using namespace std;
int n,a[10005],k;
char c[10005];
string s;
bool hu(string e)
{
	for(int i=1;i<=k/2;i++)
	{
		if(e[i]!=e[k-i+1])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s[++k]=c[i];
		}
	}
	for(int i=1;i<=k/2;i++)
	{
		cout<<s[i]<<" "<<s[k-i+1]<<endl;
		if(s[i]!=s[k-i+1])
		{
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=k/2;i++)
	{
		cout<<s[i]<<" "<<s[k-i+1]<<endl;
		if(s[i]!=s[k-i+1])
		{
			cout<<0;
			return 0;
		}
	}
 } 
