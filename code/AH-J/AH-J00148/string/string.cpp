//100 pts
#include<bits/stdc++.h>
using namespace std;
long long ans = 0;
struct str{
	long long k;
	char c;
}a[200005];
int n;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n;
	for (int i = 1;i<=n;i++) cin>>a[i].k>>a[i].c;
	int l = 1,r = n;
	for (;l<r;l++) {
		while (l<r&&a[l].k>=a[r].k) {
			if (a[l].c!=a[r].c) ans+=a[r].k;
			a[l].k-=a[r].k;
			r--;
		}
		if (a[l].c!=a[r].c) ans+=a[l].k;
		a[r].k-=a[l].k;
	}
	cout<<ans<<endl; 
	return 0;
}
