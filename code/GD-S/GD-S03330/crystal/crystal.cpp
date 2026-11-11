#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10,INF=0x3f3f3f3f;
int n;
ll m,a[N],s[N];
int chk(int x) {
	for(int i=1;i<=n-x+1;i++) {
		ll vl=a[i+x-1]*x-(s[i+x-1]-s[i-1]);
		if(vl<=m) return 1;
	}
	return 0;
}
void QwQ() {
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n,rs=1;
	while(l<=r) {
		int md=l+r>>1;
		if(chk(md)) l=(rs=md)+1;
		else r=md-1;
	}
	printf("%d\n",rs);
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
	while(T--) QwQ();
}
