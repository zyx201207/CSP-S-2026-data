#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,nxt[2000011];
ll d,a[2000011];
int s[2000011];

void solve(){
	cin >> n >> d;
	for(int i=0;i<=n+1;i++)
		s[i]=nxt[i]=a[i]=0;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int l=1,r=1;l<=n;l++){
		while(r<=n&&a[r]-a[l]<=d) r++;
		nxt[l]=r-1;
	}
	ll ans=0;
	for(int l=1,r=2;l<=n;l++){
		for(;r<=nxt[l];r++)
			for(int i=r;i<=nxt[r];i++)
				s[i]++;
		for(int i=nxt[l]+1;i<=n;i++)
			if(s[i]==2) ans++;
	}
	cout << ans << '\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int c,t;
	cin >> c >> t;
	while(t--) solve();
	return 0;
}


