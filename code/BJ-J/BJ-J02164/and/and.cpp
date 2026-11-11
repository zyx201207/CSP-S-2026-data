#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],ans,mx=-1,tmp;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(i==1) tmp=a[i];
		else tmp&=a[i];
		mx=max(a[i],mx);
	}
	if(m==1)
	{
		cout<<mx;
		return 0;
	}
	if(m==n) 
	{
		cout<<tmp;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++) 
	{
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
