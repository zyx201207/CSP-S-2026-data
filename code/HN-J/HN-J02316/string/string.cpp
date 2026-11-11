#include<bits/stdc++.h>
using namespace std;
long long n,a,min=100000000000,ans,num;
string s;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<=n;i++)
	{
		cin >> a >> c;
		num+=a;
		for(int j=i;j<=a;j++)
		{
			s[j]=c;
		}
	}
	for(int i=0;i<=num;i++)
	{
		if(s[i]!=s[n+1-i])
		{
			s[n+1-i]=s[i];
			ans++;
		}
	}
	cout << ans;
	return 0;
}
