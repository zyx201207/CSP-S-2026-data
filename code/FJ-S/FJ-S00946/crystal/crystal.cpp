#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+10;
int a[N],b[N],c[N];
int n,m;

bool check(int k) {
	int cost=0,lst;
	// 1-k
	for (int i=1;i<k;i++) {
		cost += b[i]*i;	
	}
	lst=cost;
	// 每次加入i
	for (int i=k+1;i<=n;i++) {
		cost = min(cost, lst-c[i-k]+c[i-1]+b[i-1]*(k-1)); 
		lst = lst-c[i-k]+c[i-1]+b[i-1]*(k-1);
	}
	return cost<=m;
}


signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<n;i++) {
		b[i]=a[i+1]-a[i];	
	}
	for (int i=n;i>=1;i--) {
		c[i]=c[i+1]+b[i];
	}
	int l=1,r=n+1;
	while (l+1!=r) {
		int mid=(l+r)>>1;
		if (check(mid)) l=mid;
		else r=mid;
	} 
	cout << l;
	return 0;
}
