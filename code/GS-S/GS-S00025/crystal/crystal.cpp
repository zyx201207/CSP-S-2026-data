#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
long long a[N];
int main()
{
freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long pos=0;
	for(long long i = n;i>=1;i--)
	{
		long long s = 0;
		for(long j = 1;j<=i;j++)
		{
			s += a[i] - a[j];
		}
		if(s<=m&&pos==0)
		{
			pos=i;
		}
	}
	cout<<pos;
	return 0;
}
