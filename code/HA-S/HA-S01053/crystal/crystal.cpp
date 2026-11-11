//rp++
//1~9+AB ~pts65
#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=5e5+10;

ll n,m;
ll a[N];
ll ans;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>5e3) {
		ll k,sum=0,cnt=1;
		k=a[2]-a[1];
		while(cnt<n&&sum+cnt*k<=m) {
			sum+=cnt*k;
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	for(int i=n; i>=1; i--) {
		ll cost=0,cnt=0;
		while(i-cnt>0&&cost+a[i]-a[i-cnt]<=m) {
			cost+=a[i]-a[i-cnt];
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;

	return 0;
}
