#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int N=2e5+10;
int s[N];
char c[N];
int n;
int ans;
int l,r;
int cntl,cntr;
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>s[i]>>c[i];
	}
	l=1,r=n;
	cntl=s[l],cntr=s[r];
	while(l<r) {
		int tmp=min(cntl,cntr);
		cntl-=tmp;
		cntr-=tmp;
		if(c[l]!=c[r]) {
			ans+=tmp;
		}
		if(cntl==0) {
			cntl=s[++l];
		}
		if(cntr==0) {
			cntr=s[--r];
		}
	}
	cout<<ans;
	return 0;
}
