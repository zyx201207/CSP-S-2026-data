#include<bits/stdc++.h>
using namespace std;
string s;
char a;
unsigned long long i,c=0,n,x,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x>>a;
		x=x+c;
		for(;c<x;c++)
		{
			s[c]=a;
		}
	}
	
	for(i=0;i<(x/2);i++)
	{
		if(s[i]!=s[x/2-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
