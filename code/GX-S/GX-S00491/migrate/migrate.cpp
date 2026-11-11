#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	vector<ll> a(n);
	for(auto &x:a) cin>>x;
	sort(a.begin(),a.end());
	vector<ll> pre(n+1,0);
	for(int i=0;i<n;i++){
		pre[i+1]=pre[i]+a[i];
	}
	auto check=[&](ll k)->bool{
		if(k==0) return true;
		deque<ll> dq;
		for(int i=0;i<n;i++){
			while(!dq.empty()&&a[dq.back()]-dq.back()<=a[i]-i) dq.pop_back();
			dq.push_back(i);
			if(i>=k-1){
				ll start=i-k+1;
				while(dq.front()<start) dq.pop_front();
				ll mx=a[dq.front()]-dq.front();
				ll t=mx+start; 
				__int128 cost=(__int128)k*t+(__int128)k*(k-1)/2-(pre[start+k]-pre[start]);
				if(cost<=(__int128)m) return true;
			}
		}
		return false;
	};
	ll l=1;
	ll hi=n;
	ll ans=0;
	while(l<=hi){
		int mid=l+(hi-l)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else hi=mid-1;
	}
	cout<<ans<<"\n";
	return 0;
}
