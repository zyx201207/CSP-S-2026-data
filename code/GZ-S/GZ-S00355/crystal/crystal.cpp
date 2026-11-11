//观山湖中学 梁洪锐 GZ-S00355 
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl '\n'
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f,mod=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<ll>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end(),greater<ll>());
	deque<ll>d;
	ll cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		d.push_back(a[i]);
		cnt+=d.front()-d.back();
		if(cnt>m){
			ll f=d.front();
			d.pop_front();
			cnt-=(f-d.front())*d.size();
		}
		ll len=d.size();
		ans=max(ans,len);
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
