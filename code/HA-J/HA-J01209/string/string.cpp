#include<bits/stdc++.h>
using namespace std;
int n,m=0;
int p=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("srting.out","w",stdout);
	string s;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		char y;
		cin>>x;
		cin>>y;
		m+=x;
		for(int j=1;j<=x;j++)
		{
			s[i*j+j]=y;
		}
	}
	int o=m/2;
	
	for(int i=1;i<=o;i++)
	{
		if(s[o+i]!=s[o-i])
		{
			p++;
		}
	}
	cout<<p;
	return 0;
}
