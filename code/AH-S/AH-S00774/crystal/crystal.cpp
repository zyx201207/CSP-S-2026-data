#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+10;
int n,m,a[N],c[N];
bool check(int k) {
	for(int i=k;i<=n;i++) {
		int cha=a[i]*k-(c[i]-c[i-k]);
		if(cha<=m) return 1;
	}
	return 0;
}
int bfind (int l,int r) {
	while(l<r) {
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}
		else r=mid-1;
	}
	return l;
}
bool cmp(int x,int y) {
	return x<y;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) 
		c[i]=a[i]+c[i-1];
	cout<<bfind(0,n);
	return 0;
}

