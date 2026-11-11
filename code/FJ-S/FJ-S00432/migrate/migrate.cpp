#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3f;
int c,T,n,d,x[2000010],ans,t,l,r,cnt,id[4000010],L[4000010],R[4000010];
map<int,int> mp;
struct Node
{
	int l,r,lx,rx,x;
}a[4000010];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>T;
	while (T--)
	{
		for (int i=1;i<=n;i++) L[i]=R[i]=0;
		cin>>n>>d;
		ans=cnt=0;
		for (int i=1;i<=n;i++)
		{
			cin>>x[i];a[i].lx=a[i].rx=1;
		}
		for (int i=1;i<=n;i++) a[i].x=i;
		l=1;
		for (int r=1;r<=n;r++)
		{
			while (l<r && x[l]+d<x[r]) ++l;
			a[r].l=l;
		}
		r=n;
		for (int l=n;l>=1;l--)
		{
			while (l<r && x[l]+d<x[r]) --r;
			a[l].r=r;
		}
//		for (int i=1;i<=n;i++) cout<<a[i].l<<' '<<a[i].r<<'\n';
		for (int i=1;i<=n;i++)
		{
			a[i].lx+=L[a[i].l];
			L[a[i].r]+=a[i].lx;
		}
		for (int i=n;i>=1;i--)
		{
			a[i].rx+=R[a[i].r];
			R[a[i].l]+=a[i].rx;
		}
		for (int l=1;l<=n;l++)
		{
			r=l;
			while (r<n && a[r].l+1<a[l].r) r++;
			if (a[r].l+1==a[l].r && a[r].l+1!=a[r].x)
			{
				ans+=a[l].lx*a[r].rx;
//				cout<<a[l].lx<<' '<<a[r].rx<<' '<<l<<' '<<r<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

