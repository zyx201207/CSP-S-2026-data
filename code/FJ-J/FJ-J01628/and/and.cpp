#include <bits/stdc++.h>
using namespace std;
long long n,m,x[200005],maxn,minn=pow(2,30),ms;
int len[200005],a[200005][35];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&x[i]);
		maxn=max(maxn,x[i]);
		if(x[i] < minn) {
			minn=x[i];
			ms=i;
		}
		long long t=x[i];
		while(t) {
			if(t&1) {
				a[i][len[i]++]=1;
			}
			t>>=1;

		}
	}
	if(m==1) {
		cout <<maxn<<endl;
		return 0;
	}
	if(m==n) {
		long long ans=0;
		bool ok=true;
		for(int j=1; j<len[minn]; ++j) {
			for(int i=0; i<=n; i++) {
				if(a[i][j]==0) {
					ok=false;
					break;
				}
			}
			if(ok) {
				ans+=pow(2,j);
			}
		}
		cout <<ans<<endl;
		return 0;
	}
	sort(x+1,x+1+n);
	cout <<x[n-m+1]<<endl;
	return 0;
}

