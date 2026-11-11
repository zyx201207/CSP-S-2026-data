#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],sum;
char c[200005];
string s;
int main ()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin >> n ;
	string s1;
	for (int i=0;i<n;i++)
	{
		cin >> a[i] >> c[i] ;
		for (long long j=0;j<a[i];j++)
		{
			s=s+c[i];
		}
		sum+=a[i];
	}
	long long ans=0;
	for (long long i=0;i<sum/2;i++)
	{
		if (s[i]!=s[i+(sum/2)+1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
