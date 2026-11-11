#include<bits/stdc++.h>

using namespace std;
string a;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long cnt=0;

	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		string y;
		cin>>y;
		for(int j=1;j<=x;j++)
		{
			a+=y;
		}
	
	}
	int l=a.size();
	for(int i=0;i<(l/2);i++)
	{
		if(a[i]!=a[l-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
}