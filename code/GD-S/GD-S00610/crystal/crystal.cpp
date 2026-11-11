#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

const int N=5e5+10;
int T=1, n, ans;
ll m;
ll a[N], s[N];


int ask(int i) {
	int l=0, r=i;
	while(l+1<r) {
		int mid=(l+r)/2;
		ll lim=1ll*a[i]*(i-mid)-s[i-1]+s[mid-1];
		if(lim<=m) r=mid;
		else l=mid;
	}
	return r;
}

void solve() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++) s[i]=s[i-1]+a[i];
	for(int i=1; i<=n; i++) {
		if(a[i]==a[i-1]&&i!=1) continue;
		int k=i-ask(i)+1;
//		cout<<i<<' '<<ask(i)<<'\n';
		for(int j=i+1; j<=n; j++) {
			if(a[j]==a[i]) k++;
			else break;
		}
		ans=max(ans, k);
	}
	cout<<ans;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	while(T--) solve();
	return 0;
}
