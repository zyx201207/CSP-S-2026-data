#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	char c=getchar();
	ll x=0,f=1;
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const ll MAXN=305;
ll c,t,x[MAXN],fl[MAXN][MAXN],ans[MAXN][MAXN],cnt;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	if(c<=6) {
		while(t--) {
			cnt=0;
			memset(ans,0,sizeof(ans));
			memset(x,0,sizeof(x));
			memset(fl,0x3f,sizeof(fl));
			ll n=read(),d=read();
			for(ll i=1; i<=n; i++) {
				x[i]=read();
			}
			for(ll i=1; i<=n; i++) {
				for(ll j=1; j<=n; j++) {
					if(abs(x[j]-x[i])<=d&&i!=j) {
						fl[i][j]=1;
					}
				}
			}
			for(ll k=1; k<=n; k++) {
				for(ll i=1; i<=n; i++) {
					for(ll j=1; j<=n; j++) {
						if(i!=j) {
							if(fl[i][k]+fl[k][j]<fl[i][j]) {
								ans[i][j]=0;
								fl[i][j]=fl[i][k]+fl[k][j];
							}
							if(fl[i][k]+fl[k][j]==fl[i][j]) {
								ans[i][j]++;
							}
						}
					}
				}
			}
			for(ll i=1; i<=n; i++) {
				for(ll j=1; j<=n; j++) {
					if(ans[i][j]==2&&i!=j) {
						cnt++;
					}
				}
			}
			printf("%lld\n",cnt/2);
		}
	} else if(c==13||c==14) {
		while(t--) {
			cnt=0;
			ll n=read(),d=read();
			for(ll i=1; i<=n; i++) {
				x[i]=read();
			}
			for(ll i=1; i<=n; i++) {
				for(ll j=1; j<=n; j++) {
					if(abs(x[j]-x[i])<=d&&i!=j) {
						cnt++;
					}
				}
			}
			ll nb=n*(n-1)/2;
			printf("%lld\n",cnt-1-nb);
		}
	}
	return 0;
}

