#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],c[N],d[N];
int n,m,ans,cur;
void query(int p,int l,int r)
{
	if(l==r) 
	{
		cur=l;
		return ;
	}
	int mid=(l+r)/2;
	if(c[p]-c[mid]-(mid-1)*(d[p]-d[mid])>m) query(p,mid+1,r);
	else query(p,l,mid);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	c[1]=0;
	for(int i=2;i<=n;i++)
	{
		c[i]=(a[i]-a[i-1])*(i-1);
		c[i]+=c[i-1];
		d[i]=a[i]-a[i-1];
		d[i]+=d[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		query(i,1,i);
		ans=max(ans,i-cur+1);
	}
	cout<<ans<<endl;
	return 0;
}