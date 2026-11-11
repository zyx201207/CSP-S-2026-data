#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n; 
	cin>>n;
	long long m;
	cin>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long i=abs(a[n]-a[n-1]);
	long long j=1;
	while(m>=i)
	{
		m-=i;
		i=i+abs(a[n]-a[n-1]);
		j++;
	}
	cout<<j;
	return 0;
}
