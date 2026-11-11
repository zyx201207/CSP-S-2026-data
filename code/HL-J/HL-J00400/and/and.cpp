#include<bits/stdc++.h>
using namespace std;
long long n,m,ans = 0;
int a[200005];
	
int r(int m2,int b) {
	int h = a[b];
	if(m2 == 1){
		return 0;
	}
	r(m2-1,b+1);
	h = (h & a[b+1]);
	return h;
}


int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
	for(int q = 1;q<=n;q++) {
    	cin >> a[q];
	}
	sort(a,a+n+1);
	for(int i = 1;i <= n;i++) {
		if(r(m,i) >= ans) {
			ans = r(m,i);
		}
	}
	cout << ans;
    return 0;
}
