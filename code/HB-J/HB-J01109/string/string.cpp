#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long int n=0,b=1,c=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long int m=0;
		char a;
		cin>>m>>a;
		for(int j=1;j<=m;j++)
		{
			s[b]=a;
			b++;
		}
	}
	b--;
	for(int i=1;i<=b/2;i++)
	{
		if(s[i]!=s[b-i+1])
		{
			c++;
		}
	}
	cout<<c;
	return 0;
}
