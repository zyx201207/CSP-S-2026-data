#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,d;
	long long s,n;
	long long q=0;
	cin>>n;
	for (long long i=1;i<=n;i++)
	{
		cin>>s;
	    cin>>d;
		for (int i=1;i<=s;i++)
		{
			a+=d;
		}
	}
	for (long long i=0;i<=a.length()/2;i++)
	{
		if (a[i]!=a[a.length()-i-1])
		{
			q++;
		}
	}
	if (a.length()%2==1)
	{
		cout<<q;
	}
	else
	{
		cout<<q-1;
	}
	return 0;
}

