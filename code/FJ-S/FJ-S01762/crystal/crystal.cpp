#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500100],b[500100],ans,sum;
struct segmenttree{
	ll sum[4001000],tag[4001000];
	void up(int u)
	{
		sum[u]=sum[u<<1]+sum[u<<1|1];
	}
	void down(int u,int l,int r)
	{
		if(tag[u]!=0)
		{
			int mid=(l+r)>>1;
			sum[u<<1]+=1ll*(mid-l+1)*tag[u];
			sum[u<<1|1]+=1ll*(r-mid)*tag[u];
			tag[u<<1]+=tag[u],tag[u<<1|1]+=tag[u];
			tag[u]=0;
		}
	}
	void update(int u,int l,int r,int b,int e,ll k)
	{
		if(b<=l&&r<=e)
		{
			sum[u]+=k*(r-l+1);
			tag[u]+=k;
			return ;
		}
		down(u,l,r);
		int mid=(l+r)>>1;
		if(b<=mid)update(u<<1,l,mid,b,e,k);
		if(mid<e)update(u<<1|1,mid+1,r,b,e,k);
		up(u);
	}
	ll query(int u,int l,int r,int b,int e)
	{
		if(b<=l&&r<=e)return sum[u];
		down(u,l,r);
		int mid=(l+r)>>1;
		ll res=0;
		if(b<=mid)res+=query(u<<1,l,mid,b,e);
		if(mid<e)res+=query(u<<1|1,mid+1,r,b,e);
		return res;
	}
}t;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
	ll cnt=1;
	for(int i=2;i<=n;i++)
	{
		t.update(1,1,n,1,1,b[i]*(i-1));
		t.update(1,1,n,2,i-1,-b[i]);
		while(cnt<=i-1&&t.query(1,1,n,1,cnt)>m)ans=max(ans,i-cnt),cnt++;
	}
	if(!ans)ans=n;
	cout<<ans<<endl;
	return 0;
}