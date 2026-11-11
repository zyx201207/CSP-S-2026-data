#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	long long ma=-1;
	
	for(int i=1;i<=n-m;i++)
	{
		long long t=b[i];
		for(int j=i+1;j<=i+m;j++)
		{
			t=t&b[j];
		}
		ma=max(ma,t);
	}
	cout<<ma;
	return 0;
}

