#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128;
const ll N=2e6;
struct str{
	ll x;
	set<ll>fr;
	map<ll,ll>cn,sz;
}a[N+10];
ll n,d,ans;
inline void js(){
	cin>>n>>d;
	ans=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].fr.clear();
		a[i].cn.clear();
		a[i].sz.clear();
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n&&a[j].x-a[i].x<=d;j++){
			a[j].fr.insert(i);
			a[j].cn[i]=1;
			a[j].sz[i]=1;
			{
				auto f=a[i].fr.begin();
				auto c=a[i].cn.begin(),s=a[i].sz.begin();
				for(;f!=a[i].fr.end();++f,++c,++s){
					if(a[j].cn[*f]==0){
						a[j].cn[*f]=(*c).second+1;
						a[j].sz[*f]=(*s).second;
						a[j].fr.insert(*f);
					}else if(a[j].cn[*f]==(*c).second+1){
						a[j].sz[*f]++;
					}
				}
			}
		}
		for(auto s=a[i].sz.begin();s!=a[i].sz.end();++s){
			if((*s).second==2){
				ans++;
			}
		}
		a[i].fr.clear();
		a[i].cn.clear();
		a[i].sz.clear();
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen(".ky","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	ll c,t;
	cin>>c>>t;
	for(ll i=1;i<=t;i++){
		js();
	}
	return 0;
}
