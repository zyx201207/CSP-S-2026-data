#include<bits/stdc++.h>
using namespace std;
long long a[50005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
	{
		sort(a,a+n);
		a[i]++;
	}
	for(int i=1;i<n;i++)
	{
		if(a[i-1]==a[i])
			cnt++;
	}
	cout<<cnt;
	return 0;
}
