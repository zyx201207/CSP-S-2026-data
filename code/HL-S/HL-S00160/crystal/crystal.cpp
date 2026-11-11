#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,a[500005];
	long long m,b[500005];
	b[0]=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+i;
	}
	sort(a+1,a+n+1);
	long long d=a[2]-a[1];
	for(int i=1;i<=n;i++)
	{
		if(b[i]*d>m)
		{
			cout<<b[i-1]*d;
			return 0;
		}
	}
	return 0;
}
