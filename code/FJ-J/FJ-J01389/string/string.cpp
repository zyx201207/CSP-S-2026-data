#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,p1,p2,cnt1,cnt2;
ll ans;
ll pre[N];
int a[N];
char c[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
		pre[i]=pre[i-1]+a[i];
	}
	p1=1; p2=n;
	for(int i=1;i<=n;i++) {
		if(p1==p2) break;
		if(a[p1]-cnt1<a[p2]-cnt2) {
			if(c[p1]!=c[p2]) ans+=a[p1]-cnt1;
			cnt2+=a[p1]-cnt1;
			p1++; cnt1=0;
		}
		else {
			if(c[p1]!=c[p2]) ans+=a[p2]-cnt2;
			cnt1+=a[p2]-cnt2;
			p2--; cnt2=0;
		}
	}
	cout<<ans;
	return 0;
}
// csp-j 2026 1=
// 求求了，给我1=吧 
