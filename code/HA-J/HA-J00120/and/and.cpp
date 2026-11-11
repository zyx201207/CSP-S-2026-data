#include<bits/stdc++.h>
using namespace std;
long long n,m,q,a[10000005],maxx=-0x3f3f3f3f;
string s;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			q=a[i]&&a[j];
			maxx=max(maxx,q);
		}
	}
	cout<<maxx;
	return 0;
}

