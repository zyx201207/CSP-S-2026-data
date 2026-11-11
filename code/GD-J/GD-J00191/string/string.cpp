#include<bits/stdc++.h>
using namespace std;
long long n,a[1000100],l,r,li,ri,ans,m;
char c[1001000];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	if(n==1) {
		cout<<"0";
		return 0;
	}
	l=1,r=n;
	li=a[1];
	ri=a[n];
	for(int i=1; i<=n; i++) {
		if(l>=r)break;
		if(c[l]!=c[r]) {
			ans+=min(li,ri);
		}
		if(li<ri) {
			l++;
			long long u=li;
			li=a[l];
			ri-=u;
		} else {
			if(li==ri) {
				l++,r--;
				li=a[l],ri=a[r];
			} else {
				if(ri<li) {
					r--;
					long long u=ri;
					ri=a[r];
					li-=u;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
