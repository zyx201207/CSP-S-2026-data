#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll a[500005];
deque<int> dq;
ll sum[500005];
ll llmax(ll a, ll b){
	if(a>b) return a;
	else return b;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1, a+1+n);
	for(int i=1; i<=n; i++) sum[i]=sum[i-1]+a[i];
	ll ans=0;
	for(int i=1; i<=n; i++){
		while(!dq.empty() && ((a[i]*(ll)dq.size())-(sum[i-1]-sum[dq.front()-1]))>m){
			dq.pop_front();
		}
		dq.push_back(i);
		ans=llmax(ans, dq.size());
	}
	cout<<ans<<'\n';
	return 0;
}
