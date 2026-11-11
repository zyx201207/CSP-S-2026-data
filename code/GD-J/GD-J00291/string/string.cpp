#include <bits/stdc++.h>
using namespace std;
long long n,as,asl;

struct no{
	long long x;
	string c;
}a[200009];
bool f=0;
string s;
int main()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin >>n;
	for (int i=1;i<=n;i++)
	{
		cin >>a[i].x>>a[i].c;
		asl+=a[i].x;
		f=1;

		if (a[i-1].c==a[i].c&&i!=1)
			f=0;
	}
	if (f==0)
	{
		cout <<"0";
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		long long l=a[i].x;			
		while (l--)
		{
			s=s+a[i].c;
		}
	}
	for (int i=1;i<(asl/2+1);i++)
	{
		if (s[i]!=s[asl+1-i])
		{
			as++;
		}
	}
	cout <<as;
	return 0;
}
