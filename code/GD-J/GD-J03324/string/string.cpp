#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5+5;
int n,L,a[maxn];
char c[maxn];
int qzs[maxn],qze[maxn];
int findx(int x){
	int ans = -1,l = 1,r = n;
	while (l <= r){
		int mid = (l+r)>>1;
		if (qzs[mid] < x){
			ans = mid;
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	return ans;
}
signed main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		qzs[i] = L;
		L += a[i];
		qze[i] = L;
//		cout << qzs[i] << ' ' << qze[i] << '\n';
	}
//	for (int i = 1;i <= L;i++){
//		cout << findx(i) << ' ';
//	}
	int ans = 0,zz = 1;
	while (zz <= L/2){
		int l = findx(zz);
		int r = findx(L-zz+1);
		int l_to_r = qze[l] - zz + 1;
		int r_to_l = (L-zz+1) - qzs[r];
//		cout << zz << ':' << l_to_r << ' ' << r_to_l << '\n';
		
		if (c[l] != c[r]) ans += min(l_to_r,r_to_l);
		zz += min(l_to_r,r_to_l);
	}
	cout << ans;
}
