#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+5;
int n, m, f[N][35], vis[N];
ll a[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) {
		scanf("%lld", &a[i]);
		ll t=a[i];
		int l=0;
		while(t) {
			f[i][l++]=t%2;
			t>>=1;
		}
		vis[i]=1;
	}
	ll ans=0;
	for(int i=30;i>=0;i--) {
		int cnt=0;
		for(int j=1;j<=n;j++) {
			if(!vis[j]) continue;
			if(f[j][i]) {
				cnt++;
			}
		}
		if(cnt>=m) {
			for(int j=1;j<=n;j++) {
				if(!f[j][i]) {
					vis[j]=0;
				}
			}
			ans+=(1LL<<i);
		}
	}
	printf("%lld", ans);
	return 0;
} 
