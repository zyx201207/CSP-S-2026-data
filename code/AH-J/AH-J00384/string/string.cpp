#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,s1;
	char b,c[1000005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		for(int i=1;i<=a;i++)
		{
			c[i+s1]=b;
		}
		s1+=a;
	}
	int s2=0;
	for(int i=1;i<=s1/2;i++)
	{
		if(c[i]!=c[s1-i+1])
		{
			c[s1-i+1]=c[i];
			s2++;
		}
	}
	cout<<s2;
}
