#include <bits/stdc++.h>
using namespace std;
int a,n;
char x;
int ans;
string s=" ";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	cin>>n;
	for (int i = 1;i<=n;i++)
	{
		cin>>a>>x;
		for (int i = 1;i<=a;i++)
		{
			s+=x;
		}
	}
	long long l=s.length()-1;
	for (int i = 1;i<=l/2;i++)
	{
		if (s[i]!=s[l+1-i])
		{
			ans++;
		}
	}
	cout<<ans;
}
