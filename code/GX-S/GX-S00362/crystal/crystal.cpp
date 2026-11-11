#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long n,m,a[500005],b[500005];
long long c[500005],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
	}
	bool c13 = true,c16 = true;
	long long c16t = a[2] - a[1];
	for (int i = 1;i<=n;i++){
		if (a[i] != i) c13 = false;
		if (a[i] - a[i-1] != c16t && i != 1){
			c16 = false;
			break;
		}
	}
	if (c13 || c16){
		int i = n/2;
		for (int j = 1;j<=n;j++){
			long long t1 = abs(a[i] - a[j]);
			c[j] = t1;
		}
		sort(c+1,c+1+n);
		// for (int i = 1;i<=n;i++){
		// 	cout << c[i] << " ";
		// }
		long long t5 = m,t6 = 0,j=0;
		while(t5>=0){
			if (j > n) break;
			t5 -= c[++j];
			t6++;
		}
		cout << t6-1 << endl;
		return 0;
	}
	for (int i = 1;i<=n;i++){ // i->now
		long long cnt = 0,sum1 = 0;
		// for (int j = 1;j<=n;j++){
		// 	long long t1 = abs(a[i] - a[j]);
		// 	c[j] = t1;
		// }
		for (int j = i;j>0;j--){ // left
			long long t1 = abs(a[i] - a[j]);
			sum1 += t1;
			c[++cnt] = t1;
			if (sum1 > m) break;
		} 
		sum1 = 0;
		for (int j = i+1;j<=n;j++){ // right
			long long t1 = abs(a[i] - a[j]);
			sum1 += t1;
			c[++cnt] = t1;
			if (sum1 > m) break;
		} 
		// for (int i = 1;i<=n;i++){
		// 	cout << c[i] << " ";
		// }
		// cout << endl;
		sort(c+1,c+1+cnt);
		long long t5 = m,t6 = 0,j=0;
		while(t5>=0){
			if (j > n) break;
			t5 -= c[++j];
			t6++;
		}
		// long long sum2 = 0,tans = 0;
		// for (int i = 1;i<=n;i++){
		// 	if (sum2 + c[i] <= m){
		// 		sum2 += c[i];
		// 		tans++;
		// 	}
		// }
		ans = max(ans,t6-1);
	}
	cout << ans << endl;
	return 0;
}