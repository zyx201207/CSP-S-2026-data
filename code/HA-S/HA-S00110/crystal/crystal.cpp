#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],b[N];
int n,m,ans,m1;
bool check(int mid) {
	int cnt=0;
	for(int i=1; i<=mid; i++) {
		b[i]=a[mid]-a[i];
	}
	for(int i=1; i<=mid; i++) {
		if(m1>=b[i]) {
			m1-=b[i];
			cnt++;
		} else break;
	}
	if(cnt<=ans) {
		return 0;
	}
	ans=cnt;
	return 1;
}
signed main() {
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int f=1,d,p=1;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=i) p=0;
		if(i==2) d=a[2]-a[1];
		if(i>1&&a[i]-a[i-1]!=d) f=0;
	}
	sort(a+1,a+n+1);
	if(f){
		cout<<ceil(m*1.0/d)<<'\n';
		return 0;
	}
	if(p){
		cout<<m/2;
		return 0;
	}
	int l=1,r=n;
	while(l+1<r) {
		m1=m;
		int mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<ans<<'\n';
	return 0;
}
