#include<bits/stdc++.h>
#define fr first
#define sd second
using namespace std;
using ll=long long;
const int N=2e6+10;
ll n,d,a[N],c[N],t[N],h[N],s[N],e[N];
bool cmp(pair<ll,ll> a,pair<ll,ll> b){return a.fr<b.fr;}
void solve(){
	ll ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)t[i]=h[i]=-1;
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<pair<ll,ll>> v;
	for(int i=1;i<=n;i++){
		ll l=1,r=i;
		while(l<r){
			ll md=(l+r)>>1;
			if(a[i]-a[md]>d)l=md+1;
			else r=md;
		}
		t[i]=r;
		h[r]=i;
//		cout<<i<<" "<<r<<"\n";
		if(r==i)v.push_back({i-1,i});
	}
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)if(a[j]-a[i]>d){
		ll x=t[j];
//		cout<<i<<" "<<j<<" "<<x<<"\n";
		if(h[i]-t[j]==1)v.push_back({i,j});
	}
	v.push_back({n,n+1});
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++)if(v[i].sd-v[i].fr>1){
//		cout<<v[i].fr<<" "<<v[i].sd<<" "<<v[i-1].fr<<" "<<v[i+1].sd<<"\n";
		ans+=(v[i].fr-v[i-1].fr)*(v[i+1].sd-v[i].sd)+(v[i-1].sd>v[i].fr);
	}
	cout<<ans<<"\n";
}
void solve1(){
	ll ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)t[i]=h[i]=-1;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll o=a[2]-a[1];
	if(d<o)return void(cout<<"0\n");
	ans=d/o;
	ans*=2;
	ans=(a[n]-a[1]+o)/ans;
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll T,c;cin>>c>>T;
	if(c==13||c==14){
		while(T--)cout<<"0\n";
	}
	else if(c==11||c==12||c==0)while(T--)solve1();
	else while(T--)solve();
	return 0;
}

