#include <bits/stdc++.h>
using namespace std;
//using ll = long long;
long long n,m;
long long a[500005]={};
long long arr[500005]={};
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	 } 
	sort(a+1,a+n+1);
	long long ans=-1,cnt=0;
	for(int i=n-1;i>=1;i--)
	{
		arr[i]=arr[i+1]+a[n]-a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i+1;j<=n;j++){
			if(arr[i]-arr[j]-(a[n]-a[j])*(j-i)<=m){
				ans=max(ans,j-i+1);
			} 
		}
	 } 
	cout<<ans;
	return 0;
}



