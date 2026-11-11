#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen ("string.in",'r',stdin);
	freopen ("string.out",'w',stdin);
	int n;
	cin>>n;
	int a[n];
	char c[n];
	string b;
	int num=0;
	cin>>a[0];
	cin>>c[0];
	b=c[0];
	for (int j=2;j<=a[0];j++)
	{
		b+=c[0];
	}
	for (int i=1;i<n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		for (int j=1;j<=a[i];j++)
		{
			b+=c[i];
		}
	}
	for (int i=0;i<n/2;i++)
	{
		for (int j=n;j>=n/2;j--)
		{
			if (b[i]!=b[j]) num++;
		}
	}
	cout<<num;
	fclose (stdout);
	fclose (stdout);
	return 0;
}
