#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

const int N=2e6+10;
int n, c, T, x[N];
ll d;
ll a[N], f[N], g[N];

bool check(int x, int y) {
	return (a[y]-a[x]<=d);
}

void solve() {
	cin>>n>>d;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) x[i]=lower_bound(a+1, a+i, a[i]-d)-a;
	ll ans=0;
	for(int i=1; i<=n; i++) {
		f[i]=0, g[i]=1;
		for(int j=i+1; j<=n; j++) f[j]=g[j]=0;
		for(int j=i+1; j<=n; j++) {
			if(check(i, j)) f[j]=1, g[j]=1;
			else {
				int k=max(x[j], i); f[j]=f[k]+1;
				if(k+1==j) g[j]=g[k];
				if(f[k]!=f[k+1]) g[j]=g[k];
				else if(f[k+1]!=f[k+2]) g[j]=g[k]+g[k+1];
				else g[j]=3;
			}
			ans+=(g[j]==2);
		}
	}
	cout<<ans<<'\n';
}

ll res[N];

void solve2() {
	cin>>n>>d;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) x[i]=lower_bound(a+1, a+i, a[i]-d)-a;
	for(int i=1; i<=n; i++) f[i]=g[i]=0;
	f[1]=0, g[1]=1; res[1]=0;
	for(int j=2; j<=n; j++) {
		if(check(1, j)) f[j]=1, g[j]=1;
		else {
			int k=max(x[j], 1); f[j]=f[k]+1;
			if(k+1==j) g[j]=g[k];
			if(f[k]!=f[k+1]) g[j]=g[k];
			else if(f[k+1]!=f[k+2]) g[j]=g[k]+g[k+1];
			else g[j]=3;
		}
		res[j]=(g[j]==2);
	} ll ans=0;
	for(int i=2; i<=n; i++) ans+=1ll*(n-i+1)*res[i];
	cout<<ans<<'\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>T;
	while(T--) {
		if(c<=10) solve();
		else if(c==11||c==12) solve2();
	}
	return 0;
}

/*
0 1
8 3
0 1 2 4 8 10 11 13

*/
