#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
long long a[maxn];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i++) a[i] += a[i-1];
	long long l = 1, r = n, mid=0;
	while(l < r){
		mid = l+(r-l)/2;
		bool flag=0;
		long long qzx=0, zmn=0;
		for(int i = 1; i+mid-1 <= n; i++){
			qzx=mid*(a[i+mid-1]-a[i+mid-2]);
			zmn=a[i+mid-1]-a[i-1];
			if(abs(qzx-zmn) <= m){
				flag = 1;
				break;
			}
		}
		if(flag == 1) l = mid;
		else r = mid-1;
	}
	cout << l;
	return 0;
}
