#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],sum[500005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0); 
	
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int j=0;
	for(int i=1;i<=n;i++)
	{
		if(i*a[i]-sum[i]>m)
		{
			j=i-1;
			break;
		}
	}
	int i=1;
	int mx=0;
	for(;j<=n;)
	{
		int len=j-i+1;
		int s=sum[j]-sum[i-1];
		if(len*a[j]-s<=m)
		{
			mx=max(mx,len);
			j++;
		}
		else
		{
			i++;
		}
	}
	cout<<mx;
	
	return 0;
}
