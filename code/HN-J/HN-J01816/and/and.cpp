#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200010;
//const ll INF=0x3f3f3f3f3f3f3f3f;
ll n,m,a[N],ans;
//ll tr[N<<2];
//void pushup(ll x){tr[x]=(tr[x<<1]&tr[(x<<1)^1]);}
//void build(ll x,ll l,ll r)
//{
//	if(l==r)
//	{
//		tr[x]=a[l];
//		return;
//	}
//	ll mid=(l+r)>>1;
//	build(x<<1,l,mid);
//	build((x<<1)^1,mid+1,r);
//	pushup(x);
//}
//ll query(ll x,ll l,ll r,ll ql,ll qr)
//{
//	if(l>qr||r<ql) return INF;
//	if(ql>=l&&qr<=r) return tr[x];
//	ll res=0,mid=(l+r)>>1;
//	ll q1=query(x<<1,l,mid,ql,qr),q2=query((x<<1)^1,mid+1,r,ql,qr);
//	if(q1!=INF) res&=q1;
//	if(q2!=INF) res&=q2;
//	return res;
//}
bool cmp(ll A,ll B)
{
	return A>B;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
//	build(1,1,n);
//	for(int i=1;i<=n;i++) cout<<tr[i]<<' ';
//	cout<<'\n';
//	ll l=1,r=m,ans=0;
//	while(r<=n)
//	{
//		ans=max(ans,query(1,1,n,l,r));
//		cout<<query(1,1,n,l,r)<<'\n';
//		l++,r++;
//	}
//	cout<<ans<<'\n';
	for(int i=1;i<=n-m+1;i++)
	{
		ll res=a[i];
		for(int j=i+1;j<=i+m-1;j++)
		{
			res&=a[j];
		}
		ans=max(ans,res);
	}
	cout<<ans<<'\n';
	return 0;
}
