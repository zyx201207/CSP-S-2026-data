#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+50;
bool d[N][35];ll a[N];
void d6(ll n){
	cout<<a[n];
}
void d7(ll n){
	ll maxn=a[1];
	for(int i=2;i<=n;i++) maxn&=a[i];
	cout<<maxn;
}
void d8t10(ll n){
	ll maxn=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			maxn=max(maxn,a[i]&a[j]);
		}
	}
	cout<<maxn;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	ll ok=0,maxn=0;
	if(m==1){d6(n);ok=1;}
	if(m==n){d7(n);ok=1;}
	if(n<=2000&&m==2){d8t10(n);ok=1;}
	if(ok) return 0;
	vector<ll> v;ll len=n;
	for(ll i=1;i<=n;i++){
		v.push_back(i);
		ll r=a[i],cnt=0;
		while(r){
			d[i][++cnt]=r%2;
			r/=2;
		}
		maxn=max(maxn,cnt);
	}
	for(ll i=maxn;i>=1;i--){
		vector<ll> s;
		ll lenm=0;
		s.clear();
		for(ll j=0;j<len;j++){
			if(d[v[j]][i]){
				lenm++;
				s.push_back(v[j]);
			}
		}
		if(lenm>=m){
			v.clear();
			for(ll j=0;j<lenm;j++){
				v.push_back(s[j]);
			}
			len=lenm;
		}
	}
	ll ans=a[v[0]];
	for(ll j=1;j<ll(v.size());j++){
		ans&=a[v[j]];
	}
	cout<<ans;
	return 0;
}
