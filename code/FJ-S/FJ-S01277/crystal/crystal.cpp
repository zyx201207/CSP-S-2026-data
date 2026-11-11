#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int _=5e5+5;
ll n,m,a[_],s[_],ans;
bool check(int l,int r)
{
	return m>=a[r]*(r-l+1)-s[r]+s[l-1];
}
bool solve(int len)
{
	for(int i=1;i+len-1<=n;i++)
	{
		if(check(i,i+len-1))
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=a[i]+s[i-1];
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
//		cout<<mid<<" "<<solve(mid)<<endl;
		if(solve(mid)) ans=mid,l=mid+1;
		else r=mid;
	}
	cout<<ans<<endl;
	return 0;
}
