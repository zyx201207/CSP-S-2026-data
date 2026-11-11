#include<bits/stdc++.h>
using namespace std;
int a[200001];
char c[200001];
string s;
int main()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		for (int j=0;j<a[i];j++)
		{
			s+=c[i];
		}
	}
	int f=n-1,sum=0;
	for (int i=0;i<s.size()/2;i++)
	{
		if (s[i]!=s[f]) sum++;
	}
	cout<<sum;
	return 0;
}
