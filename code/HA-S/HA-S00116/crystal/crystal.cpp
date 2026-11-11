#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int n,m;
int ans;
bool check1(int x,int y)
{
	int cnt=0;
	int pos=upper_bound(a+1,a+1+n,y)-a-1;
	for(int i=pos;i>=pos-x+1;i--) cnt+=a[pos]-a[y];
	if(cnt>m) return false;
	return true;
}
bool check(int x)
{
	int l=upper_bound(a+1,a+1+n,x)-a-1,r=a[n];
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check1(x,mid)) l=mid;
		else r=mid-1;
	}
	return check1(x,l);
}
signed main()
{
	//freopen("crystal4.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
