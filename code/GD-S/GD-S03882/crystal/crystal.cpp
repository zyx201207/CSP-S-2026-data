#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5*1E5+7,INF=1E12;
	ll n,m,a[N],len,s[N],ans,h[N];
struct nod{
	ll val,c;
}p[N];
ll chk(ll r,ll t){
	ll cnt=s[r-1]-s[t-1];
	ll to=(h[r-1]-h[t-1])*p[r].val-cnt;
	if(to<=m) return m-to;
	return -1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
		cin>>n>>m;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		sort(a+1,a+n+1);
		p[1].val=a[1];
		p[1].c++;
		len++;
		for(ll i=2;i<=n;i++){
			ll v=a[i];
			if(p[len].val!=v) p[++len].val=v;
			p[len].c++;
		}
	for(ll i=1;i<=len;i++){
		s[i]=s[i-1]+p[i].val*p[i].c;
		h[i]=h[i-1]+p[i].c;
	}
	for(ll i=1;i<=len;i++){
		ll l=1,r=i-1,mid;
		ll res=-1,w=-1;
		while(l<=r){
			mid=(l+r)/2;
			ll v=chk(i,mid);
			if(v!=-1){
				res=mid;
				w=v;
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,p[i].c);
		if(res!=-1){
			ll cnt=h[i]-h[res-1];
			if(res-1>=1) cnt+=w/(p[i].val-p[res-1].val);
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
