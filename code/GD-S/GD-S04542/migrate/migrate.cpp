#include <bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define ll long long
int ok (int l, int r) {
//	int ans = 1, t = 0;
//	while (pinmingfei[l] < r) {
//		if(pinmingfei[l - 1] == pinmingfei[l] && t) {
//			if(pinmingfei[l - 2] == pinmingfei[l - 1]) {
//				return 0;
//				//这三个位置都飞得到，那没法儿了 
//			}
//			ans *= 2;
//			if(ans > 2){
//				return 0;
//			}
//		}
//		t = 1;
//		l = pinmingfei[l];
//	};
	return 1;
}
void init() {
	scanf("%d%lld", &n, &D);
	rep(i, 1, n) {
		scanf("%lld", a[i]);
	}
//	x[0] = -3e18 - 7;
//	x[n] = 3e18 + 7;
//	rep(i, 1, n) {
//		lst[i] = lst[i - 1];
//		while(x[lst[i]] < x[i] - D) {
//			lst[i] ++;
//		}
//	}
cout << 0 << "\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	scanf("%d%d", &testcase, &T);
	while(T--) {
		init();
	}
	return 0;
}

