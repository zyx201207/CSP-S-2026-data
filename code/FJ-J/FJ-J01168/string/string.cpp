#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+10;
int ans; 
struct node {
	char c;
	int len;
}a[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	int n;
	cin >> n;
	for (int i=1;i<=n;i++) {
		cin >> a[i].len >> a[i].c;
	} 
	int l=1,r=n;
	while (l<r) {
		int k=min(a[l].len, a[r].len);
		a[l].len-=k;
		a[r].len-=k;
		if (a[l].c!=a[r].c) {
			ans+=k;
		} 
		if (!a[l].len) l++;
		if (!a[r].len) r--;
	}	
	cout << ans;
	return  0;
}

