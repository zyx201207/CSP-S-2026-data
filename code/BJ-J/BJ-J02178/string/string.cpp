#include <bits/stdc++.h>
using namespace std;
int n,x[200005];
char a[200005];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int c=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>a[i];
		for(int j=1;j<=x[i];j++)
		{
			c++;
			s[c]=a[i];
		}
	}
	int ans=0;
	for(int i=1;i<=10;i++)
	{
		if(s[i]!=s[c])
		{
			ans++;
			s[c]=s[i];
		}
		c--;
	}
	cout<<ans;
	return 0;
}
