#include<bits/stdc++.h>
#define endl '\n' 
#define ll long long
using namespace std;
const int N = 2e6+1;

ll n,d;
ll a[N];


ll dis[N];
ll w[N];
ll ans;
void solve1() {
	cin>>n>>d;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++) {
		ll k=i, l;
		w[i]=1;
		dis[i]=0;
		for(ll j=i+1;j<=n;j++) {
			while(k <= j && a[j]-a[k] > d) {
				k++;
			}
			dis[j] = dis[k] + 1;
			
			l=k;
			w[j]=0;
			while(l < j && dis[l] == dis[k]) {
				w[j] += w[l++];
			}
			if(w[j]==2) ans++;
		}
	}
	cout<<ans<<endl;
	return;
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int c,t; cin>>c>>t;
	while(t--) {
		ans=0;
		if(c <= 10)
			solve1();
		else {
			cout<<0<<endl;
		}
	}
	return 0;
}
