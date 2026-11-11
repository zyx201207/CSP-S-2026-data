#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct node {
	ll c;
	char a;
};
node h[200100];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >>n;
	for(int i=1; i<=n; i++) {
		cin >>h[i].c>>h[i].a;
	}
	ll ans=0;
	ll l=1,r=n;
	char left=h[1].a,right=h[n].a;
	ll lnum=h[1].c,rnum=h[n].c;
	while(l<=r) {
		if(lnum>rnum) {
			r--;
			if(left!=right) {
				ans+=rnum;
			}
			lnum-=rnum;
			rnum=h[r].c;
			right=h[r].a;
		} else if(lnum<rnum) {
			l++;
			if(left!=right) {
				ans+=lnum;
			}
			rnum-=lnum;
			lnum=h[l].c;
			left=h[l].a;
		} else {
			l++,r--;
			if(left!=right) {
				ans+=lnum;
			}
			lnum=h[l].c,rnum=h[r].c;
			left=h[l].a,right=h[r].a;
		}
	}
	cout <<ans;
	return 0;
}

