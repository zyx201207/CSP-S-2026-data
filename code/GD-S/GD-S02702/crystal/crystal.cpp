#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long 
using namespace std;
int n,ans=1;
ll m;
ll a[500005],pre[500005];
int main()
{
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
//	for(int i=1;i<=n;i++)cout<<pre[i]<<" ";cout<<"\n";
	for(int r=1,l=1;r<n;)
	{
//		cout<<l<<" "<<r<<" "<<(r-l+1)*a[r+1]-(pre[r]-pre[l-1])<<"\n";
		if((r-l+1)*a[r+1]-(pre[r]-pre[l-1])>m)l++;
		else
		{
			ans=max(ans,r-l+1+1);
			r++;
		}
	}
	cout<<ans;
	return 0;
}
//O(n)
//maybe 100pts
