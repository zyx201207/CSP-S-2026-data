#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
bool cmp(int x,int y) {
	return x<y;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int maxx=1;
	for(int i=1; i<=n; i++) {
		int x=m,cnt=0;
		for(int j=i; j>=1; j--) {
			int y=a[i]-a[j];
			x-=y;
			if(x<0) {
				maxx=max(maxx,cnt);
				break;
			}
			cnt++;
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}
