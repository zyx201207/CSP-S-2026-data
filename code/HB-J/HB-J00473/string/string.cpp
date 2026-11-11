#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
string c[200005],s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	unsigned long long m=0,ans=0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		for (int j = 1;j <= a[i];j++)	s+=c[i];
		m+=a[i];
	}
	int len=m/2;
	for (int i = 0;i < len;i++)
	{
		if(s[i]!=s[m-i-1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
