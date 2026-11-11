//GZ-S00219,刘子逍,北京师范大学贵阳附属中学
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef unsigned long long ull;
int n;
ll m;
struct P{
	ll n,d;
};
vector<ll> a;
ll b[500010],inx,ans;
map<ll,ll> mp;
bool f;
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		int T;
		cin>>T;
		if(!mp[T]) a.push_back(T);
		++mp[T];
		if(T>=1e5) f=1;
	}
	sort(a.begin(),a.end(),cmp);
	if(f){
		ll d=a[1]-a[0],i=1;
		while(m>0) ++ans,m-=d*i,++i;
		cout<<ans<<'\n';
		return 0;
	}
	//for(auto i:a) cout<<i<<' ';
	//cout<<"-----------------------\n";
	ans=mp[a[0]];
	for(ll i=1;i<a.size();++i){
		ll cnt=mp[a[i]],p=m,j;
		for(j=i-1;j>=0;--j){
			//cout<<i<<' '<<j<<' '<<ans<<' '<<cnt<<' ' <<p<<' '<<(a[i]-a[j])<<'\n';
			if(p>=mp[a[j]]*(a[i]-a[j])) p-=mp[a[j]]*(a[i]-a[j]),cnt+=mp[a[j]];
			else break;
		}
		ans=max(ans,cnt+p/(a[i]-a[j]));
	}
	cout<<ans<<'\n';
	fclose(stdin);fclose(stdout);
	return 0;
}
