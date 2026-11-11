#include<bits/stdc++.h>
using namespace std;
long long a[6000010],b[6000010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=-9999999999999;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	for(long long i=n;i>=1LL;i--)
	{
		if((a[i]*(n-(n-i+1LL)))-b[i-1LL]<=m) ans=max(ans,i);
		//cout<<(a[i]*(n-(n-i+1)))-b[i-1]<<" ";
	}
	cout<<ans;
	//5 100
	//1 2 4 8 9
	//8 7 5 1 0
	//5
	
	//7
	
	//5 8
	//1 1 2 3 4
	//9
	//1 2 4 7 11
	//
	return 0;
}
