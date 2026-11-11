#include <bits/stdc++.h>
using namespace std;
int a[200009], ans=0;
long long n, cnt=0;
char c[200009];
string s="";
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i] >> c[i];
		cnt += a[i];
		for(int j=0;j<a[i];j++)
			s += c[i];

	}
	long long j = cnt>>1;
	if(cnt%2==0)
	{
		for(int i=0;i<=j;i++)
		{
			if(s[i]!=s[cnt-i])
				ans++;
		}
	}
	else
	{
		for(int i=0;i<j;i++)
		{
			if(s[i]!=s[cnt-i])
				ans++;
		}
	}
	cout << ans;
	return 0;
}
