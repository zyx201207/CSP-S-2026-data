#include<bits/stdc++.h>
#define int long long
#define il inline
using namespace std;
const int N=200005;
int n,cnt1,cnt2,p,z,ans;
struct node {
	int gs;
	char c;
}a[N];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i].gs>>a[i].c;
		z+=a[i].gs;
	}
	p=n;
	if(z%2) {
		for(int i=1;cnt1+cnt2+1<z;i++) {
			if(cnt1+a[i].gs<=z/2) cnt1+=a[i].gs;
			else cnt1=z/2;
			for(;p>=i && cnt1>cnt2 && cnt1+cnt2+1<z;p--) {
				if(a[i].c!=a[p].c) {
					if(cnt1>=cnt2+a[p].gs) {
						cnt2+=a[p].gs;
						ans+=a[p].gs;
					}else {
						a[p].gs-=cnt1-cnt2;
						ans+=cnt1-cnt2;
						cnt2=cnt1;
						p++;
					}
				}else {
					if(cnt1>=cnt2+a[p].gs) {
						cnt2+=a[p].gs;
					}else {
						a[p].gs-=cnt1-cnt2;
						cnt2=cnt1;
						p++;
					}
				}
			}
		}
		cout<<ans;
	}else {
		for(int i=1;cnt1+cnt2<z;i++) {
			if(cnt1+a[i].gs<=z/2) cnt1+=a[i].gs;
			else cnt1=z/2;
			for(;p>=i && cnt1>cnt2 && cnt1+cnt2<z;p--) {
				if(a[i].c!=a[p].c) {
					if(cnt1>=cnt2+a[p].gs) {
						cnt2+=a[p].gs;
						ans+=a[p].gs;
					}else {
						a[p].gs-=cnt1-cnt2;
						ans+=cnt1-cnt2;
						cnt2=cnt1;
						p++;
					}
				}else {
					if(cnt1>=cnt2+a[p].gs) {
						cnt2+=a[p].gs;
					}else {
						a[p].gs-=cnt1-cnt2;
						cnt2=cnt1;
						p++;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
