#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxn=500005;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n; ll m;
	cin>>n>>m;
	vector<ll> a(maxn);
	vector<ll> pre(maxn);
	
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int midp=0;
	midp=(n/2)+1;
	ll target=a[midp];
	
	int cnt=0;
	for (int i=1;i<=midp;i++){
		ll needle=target-a[i];
		if (m-needle<0) break;
		a[i]+=needle;
	}
	
	for (int i=1;i<=n;i++){
		if (a[i]==a[midp]) cnt++;
	}
	
	cout<<cnt;
	
	return 0;
}
