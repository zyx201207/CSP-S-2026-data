#include<bits/stdc++.h>
using namespace std;
char s[100000000000099];
int a[100099],m,l;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char b;
		cin>>a[i]>>b;
		for(int j=1;j<=a[i];j++)
		{
			m++;
			s[m]=b;
		}
		l=l+a[i];
	}
	int p=0;
	for(int i=1;i<=l/2;i++)
	{
		if(s[i]!=s[l+1-i])
		{
			p++;
		}	
	}
	cout<<p;
}

