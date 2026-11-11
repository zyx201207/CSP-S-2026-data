#include<bits/stdc++.h>
#define ll long long
#define no ios::sync_with_stdio(0);
#define TLE cin.tie(0),cout.tie(0);
using namespace std;
const ll N=1e5+5;
ll c,n,d,x[N],ans=0;
void solve(){
	cin>>n>>d;
	vector<pair<ll,bool>>lpos,rpos,_l,_r;
	for(ll i=1;i<=n;i++)cin>>x[i];
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i+3;j<=n;j++)
		{
			ll l=i,r=j,res1=-1,res2=-1;
			while(l<=r)
			{
				ll mid=(l+r)>>1;
				if(x[mid]-x[l]<=d&&x[r]-x[mid]<=d)res1=mid,r=mid-1;
				else if(x[mid]-x[l]<=d)r=mid+1;
				else l=mid-1;
			}
			l=i,r=j;
			while(l<=r)
			{
				ll mid=(l+r)>>1;
				if(x[mid]-x[l]<=d&&x[r]-x[mid]<=d)res2=mid,l=mid+1;
				else if(x[mid]-x[l]<=d)r=mid+1;
				else l=mid-1;
			}
			if(res1==-1)continue;
			if(res2-res1+1==2)lpos.push_back({res1,1}),rpos.push_back({res2,1});
			else if(res2-res1+1>2)lpos.push_back({res1,0}),rpos.push_back({res2,0});
		}
	}
	_l=lpos,_r=rpos;
	sort(_r.begin(),_r.end());
	sort(_l.begin(),_l.end());
	for(ll i=0;i<(ll)lpos.size();i++)
	{
		if(!lpos[i].second)continue;
		ll l=0,r=lpos.size()-1,res1=-1,res2=-1;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(_r[mid].first<=lpos[i].first)res1=mid,l=mid+1;
			else r=mid-1;
		}
		l=0,r=lpos.size()-1;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(_l[mid].first>=rpos[i].first)res2=mid,r=mid-1;
			else l=mid+1;
		}
		if(res1==-1)res1=1;
		else res1=lpos[i].first-_r[res1].first+1;
		if(res2==-1)res2=1;
		else res2=-rpos[i].first+_l[res2].first+1;
		ans+=res1*res2;
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	no TLE
	ll _=1;
	cin>>c>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
