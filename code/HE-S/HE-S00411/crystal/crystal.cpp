#include<bits/stdc++.h>
using namespace std;
typedef long long lo;
vector<lo> a;
lo n,m,x = 0,y,z;
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool f = true;
	scanf("%lld%lld",&n,&m);
	for(int i = 0;i < n;i++) {
		scanf("%lld",&y);
		a.push_back(y);
		if(i > 1 && a[i]-a[i-1] != a[i-1]-a[i-2]) f = false;
	}
	sort(a.begin(),a.end());
	if(f) {
		y = m;
		for(int i = n-1;i >= 0;i--) {
			if(y-a[n]+a[i] < 0) break;
			x++;
			y = y-a[n]+a[i];
		}
		printf("%lld",x);
		return 0;
	}
	for(int i = 0;i < n;i++) {
		y = m,z = 0;
		for(int j = 0;j < n;j++) {
			if(a[i]-a[j] < 0) continue;
			if(y-a[i]+a[j] < 0) break;
			z++;
			y = y-a[i]+a[j];
		}
		x = max(x,z);
	}
	printf("%lld",x);
	return 0;
}
