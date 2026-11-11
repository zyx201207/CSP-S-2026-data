#include<bits/stdc++.h>
using namespace std;
long long n,arr[500003]={0},ans=0;
unsigned long long m;
unsigned long long a[500003]={0};
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	//while(m>0)
	for(long long i=2;i<=n;i++)
	{
		for(long long c=1;c<i;c++)
		{
			//if(arr[i]-arr[c]>0)
			ans+=arr[i]-arr[c];
		}
		a[i-1]=ans;
		ans=0;
	}
	for(long long i=n-1;i>=1;i--)
	if(a[i]<=m){cout<<i+1;break;}

	return 0;
}
