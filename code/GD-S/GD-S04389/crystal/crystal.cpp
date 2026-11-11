#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1145141],b[1145141],maxn = -1,l,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1 ; i <= n ; i++) b[i] = b[i-1] + a[i];
	for(int i = 2 ; i <= n ; i++){
		long long l = 1,r = i,c;
		while(l <= r){
			long long mid = (l + r) / 2;
			if(a[i] * (i - mid + 1) - (b[i] - b[mid-1]) > m) l = mid + 1;
			else r = mid - 1,c = mid;
		}
		maxn = max(maxn,i-c+1);
	}
	cout << maxn << endl;
	return 0;
}
