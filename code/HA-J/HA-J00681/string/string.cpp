#include<bits/stdc++.h>
using namespace std;
long long n,a,c = 1,ans;
char s[200050000],f;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>f;
		for(int j=c;j<=a+c-1;j++)
		{
			s[j] = f;
		}
		c = c+a;
	}
	for(int i=1;i<=(c-1)/2;i++)
	{
		if(s[i] == s[c-i])
		{
			ans = ans;
		}
		else ans++;
	}
	cout<<ans;
	return 0;
}
