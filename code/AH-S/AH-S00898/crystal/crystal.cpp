#include<bits/stdc++.h>
#define int long long
using namespace std;
const int dd=5e5+5;
int a[dd],s[dd];
int n,m;
bool check(int v)
{
	int t=2e18;
	for(int i=1;i+v-1<=n;i++)
	{
		t=min(t,a[i+v-1]*v-(s[i+v-1]-s[i-1]));
	}
	return t<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	while(l!=r)
	{
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
