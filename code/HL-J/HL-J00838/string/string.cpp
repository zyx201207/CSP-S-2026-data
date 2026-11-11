#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
long long n,len;
long long ans;
long long a[N];
char c[N];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i]>>c[i];
		len += a[i];
		for(int j = 1;j <= a[i];j++)
		{
			s+=c[i];
		}
	}
	s = ' ' + s;
//	cout<<s;
	for(int i = 1;i <= len / 2;i++)
	{
		if(s[i] != s[len + 1 - i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}