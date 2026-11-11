#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],dis[1000001];
long long l,r,k,ans;
long long query(long long l,long long r,long long x)
{
	if(l==r)return l;
	int mid=(l+r)/2;int anss;
	if(((x-mid+1)*a[x]-dis[x]+dis[mid-1])>m)
	anss=query(mid+1,r,x);
	else anss=query(l,mid,x);
	return anss;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;if(n==1){cout<<1;return 0;}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);dis[0]=0;
	for(int i=1;i<=n;i++)dis[i]=dis[i-1]+a[i];
	for(int i=1;i<=n;i++)
	ans=max(ans,i-query(1,i,i)+1);
	cout<<ans<<endl;
	return 0;
}
