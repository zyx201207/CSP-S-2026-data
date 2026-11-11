#include <bits/stdc++.h>
using namespace std;
long long a[100000005];
long long n,x,cnt;
char b[1000000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>b[x];
		x++;
		for(int j=0;j<a[i]-1;j++)
		{
			b[x]=b[x-1];
			x++;
		}
	}
	for(int i=0;i<x/2;i++)
	{
		if(b[i]!=b[x-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
