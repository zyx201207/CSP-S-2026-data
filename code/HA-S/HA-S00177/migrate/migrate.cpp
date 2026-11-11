#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		long long n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		  cin>>a[i];
		long long mid=n/2;
		if(a[n]-a[1]>d||a[mid]-a[1]>d)  cout<<0;
	}
}
