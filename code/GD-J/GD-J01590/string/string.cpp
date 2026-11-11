#include <bits/stdc++.h>
using namespace std;
int n;
int a[10001];
string s[10001];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>s[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(s[i]==s[i-1])
		{
			cout<<0;
			
		}
		else
		{
			cout<<2; 
		}
	}
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	return 0;
}
