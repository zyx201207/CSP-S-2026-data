#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],d[N];
int check(int x)
{
	int ans=LLONG_MAX;
	for(int k=x;k<=n;k++)
	{
		int sum=x*a[k]-(d[k]-d[k-x]);
		ans=min(sum,ans);
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		d[i]=a[i]+d[i-1];
	}
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(check(mid)>m) r=mid-1;
		else l=mid;
	}
	cout<<l;
	return 0;
}
