#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[100001];
char b[100001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string c;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i]>>b[i];
		for(int j=1; j<=a[i]; j++)
		{
			c+=b[i];
		}
	}
	cout<<c;
	return 0;
}
