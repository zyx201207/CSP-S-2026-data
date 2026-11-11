#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200002],f[32],t,u_max;

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	long long h,u;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		h = a[i];
		u = 0;
		while (h > 0){
			f[u++] += h%2;
			h /= 2;
		}
		u_max = max(u_max,u-1);
	}
	for (int i = u_max;i >= 0;i--){
		if (f[i] >= m){
			int k=0;
			for (int j = 1;j <= n;j++){
				if ((((a[j] >> i) & 1) == 1)&&(((a[j] & t) == t)||(i == u_max))){
					k++;
				}
			}
			if (k >= m){
				t += (1 << i);
			}
		}
	}
	cout << t;
	return 0;
}
