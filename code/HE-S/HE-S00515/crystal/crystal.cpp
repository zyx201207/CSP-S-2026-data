#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long zd=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]-a[i]<a[i]-a[i-1])
		{
			zd=a[i]-a[i-1];
		}
	}
	cout<<zd-1;
	return 0;
}
