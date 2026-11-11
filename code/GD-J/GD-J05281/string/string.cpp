#include <bits/stdc++.h>
using namespace std;
long long ans;
int n,l,r;
vector <int> a;
vector <char> b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		int x;
		char y;
		cin>>x>>y;
		a.push_back(x);
		b.push_back(y);
	}
	r = n-1;
	while(l<r) {
		//r =
		if(b[l]!=b[r]) {
			//cout<<a[r]<<"\n";
			if(a[l] >= a[r]) {
				ans += a[r];
				a[l] -= a[r];
				r--;
			}
			if(a[r] >= a[l]) {
				ans += a[l];
				a[r] -= a[l];
				l++;
			}
		} else if(b[l] == b[r]) {
			//	cout<<a[l]<<"\n";
			if(a[l] >= a[r]) {
				a[l] -= a[r];
				r--;
			}
			if(a[r] >= a[l]) {
				a[r] -= a[l];
				l++;
			}
		}
	}
	cout<<ans;
}
