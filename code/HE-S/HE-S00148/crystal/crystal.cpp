#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50,inf=0x3f3f3f3f3f3f;
int n,m;
int a[N],ans;
int v[N];
inline int check(int mid)
{
	int sum=0,cnt=0,tot=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>mid) break;
		v[++cnt]=abs(a[i]-mid);
	}
	sort(v+1,v+1+cnt);
	for(int i=1;i<=cnt;i++) 
	{
		sum+=v[i];
		if(sum<=m) tot++;
		if(sum>m) break;
	}
	return tot;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		int t=check(a[i]);
		if(t>ans) ans=t;
	}
	cout<<ans;
	return 0;
}
