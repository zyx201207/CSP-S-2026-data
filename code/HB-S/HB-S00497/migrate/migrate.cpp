#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,l,r) for(int i=l;i>=r;i--)
using namespace std;
const int maxn=2e6+5;
ll n,d,fl[maxn],fr[maxn],nxtl[maxn],nxtr[maxn],x[maxn],l,r,ans;
void solve()
{
	cin>>n>>d;ans=0;
	rep(i,1,n)cin>>x[i];
	x[0]=-4e18,x[n+1]=4e18;
	rep(i,1,n)nxtl[i]=lower_bound(x,x+n+2,x[i]-d)-x,nxtr[i]=lower_bound(x,x+n+2,x[i]+d+1)-x-1;
	memset(fl,0,sizeof(fl));
	memset(fr,0,sizeof(fr));
	rep(i,1,n)if(nxtr[i]!=i)fl[nxtr[i]]+=fl[i]+1;
	per(i,n,1)if(nxtl[i]!=i)fr[nxtl[i]]+=fr[i]+1;
	l=1,r=0;
	rep(i,1,n-1)
	{
		if(nxtr[i]<i+2)continue;
		ll maxr=nxtr[nxtr[i]-1],minr=nxtr[nxtr[i]-2];
		while(l<minr)l++;
		while(r<maxr)r++;
		if(l==r)continue;
		ll a=((nxtl[nxtr[i]-1]>=i)?fl[i]+1:1),b=(nxtr[nxtr[i]]<=r?fr[r]+r-l:r-l);
		ans+=a*b;
	}
	cout<<ans<<'\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)solve();
	return 0;
}
