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
const ll MAXN=5e5+5;
ll n,m,a[MAXN],q[MAXN],num[MAXN];
bool f[MAXN];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(ll i=1; i<=n; i++) {
		a[i]=read();
	}
	for(ll i=1; i<=n; i++) {
		ll l=1,r=0;
		memset(f,0,sizeof(f));
		for(ll j=i; j<=n; j++) {
			++r;
			q[r]=a[j];
			if(f[a[j]]==1) {
				r--;
				while(q[r]!=a[j]){
					f[q[r]]=0;
					r--;
				}
			}
			f[a[j]]=1;
		}
		for(ll j=l;j<=r;j++){
			num[q[j]]++;
		}
	}
	for(ll i=1;i<=m;i++){
		printf("%lld ",num[i]);
	}
	return 0;
}

