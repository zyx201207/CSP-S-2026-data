#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5+5;
long long x,ans,n,m,b[N],a[N];
int main() {

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(n<=5&&m<=10) {
		if(n==1) {
			cout<<1;
		} else if(n==2) {
			if(m==1) {
				if(a[2]-a[1]<=m)cout<<2;
				else cout<<1;
			} else if(m==2) {
				if(a[2]-a[1]<=m) cout<<2;
				else cout<<1;
			} else if(m==3) {
				if(a[2]-a[1]<=m) cout<<2;
				else cout<<1;
			} else if(m==4) {
				if(a[2]-a[1]<=m) cout<<2;
				else cout<<1;
			} else if(m==5) {
				if(a[2]-a[1]<=m) cout<<2;
				else cout<<1;
			} else if(m==6) {
				if(a[2]-a[1]<=m) cout<<2;
				else cout<<1;
			} else if(m==7) {
				if(a[2]-a[1]<=m) cout<<2;
				else cout<<1;
			} else if(m==8) {
				if(a[2]-a[1]<=m) cout<<2;
				else cout<<1;
			} else if(m==9) {
				if(a[2]-a[1]<=m) cout<<2;
				else cout<<1;
			} else if(m==10) {
				if(a[2]-a[1]<=m) cout<<2;
				else cout<<1;
			}
		} else if(n==3) {
			if(a[1]==a[2]&&a[1]==a[3]) cout<<3;
			else {
				sort(a+1,a+n+1);
				for(int i=1; i<=n; i++) b[i] = a[i];
				for(int i=1; i<=n; i++) {
					if(m>=b[i]) {
						ans++;
						m-=b[i];
					} else break;
				}
			}
		} else if(n==4) {
			if(a[1]==a[4]&&a[1]==a[2]&&a[1]==a[3]) cout<<4;
			else {
				sort(a+1,a+n+1);
				for(int i=1; i<=n; i++) b[i] = a[i];
				for(int i=1; i<=n; i++) {
					if(m>=b[i]) {
						ans++;
						m-=b[i];
					} else break;
				}
			}
		} else if(n==5) {
			if(a[1]==a[5]&&a[1]==a[4]&&a[1]==a[2]&&a[1]==a[3]) cout<<5;
			else {
				sort(a+1,a+n+1);
				for(int i=1; i<=n; i++) b[i] = a[i];
				for(int i=1; i<=n; i++) {
					if(m>=b[i]) {
						ans++;
						m-=b[i];
					} else break;
				}
			}
		}
	} else {
		sort(a+1,a+n+1);
		for(int i=1; i<=n; i++) b[i] = a[i];
		for(int i=1; i<=n; i++) {
			if(m>=b[i]) {
				ans++;
				m-=b[i];
			} else break;
		}
	}

	cout<<ans+1;



	return 0;
}