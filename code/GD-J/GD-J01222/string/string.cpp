#include <bits/stdc++.h>
using namespace std;
int n,a[200010];
char b[200010];
string s;
int main()
{
	freopen("string.in","v", stdin);
	freopen("string.out","w", stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=b[i];
		}
	}
	long long l=s.size();
	long long cnt=0;
	for(long long i=l/2;i<l;i++)
	{
		if(s[i]!=s[i-l/2])
		{
			cnt++;
		}
	}
	long long ans=0;
	for(long long i=0;i<l/2;i++)
	{
		if(s[i]!=s[i+l/2])
		{
			ans++;
		}
	}
	cout << min(ans,cnt) << '\n';
	return 0;
}
