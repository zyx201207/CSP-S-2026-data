#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,l,r,mid,ans=1; 
long long m,a[N],pre[N];
bool check(int x)
{
	for(int i=x;i<=n;i++)
		if(a[i]*x-(pre[i]-pre[i-x])<=m)return 1;
	return 0; 
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	l=2,r=n;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}

