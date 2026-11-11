#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N],pre[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	long long ans = 0;
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		pre[i]+=(pre[i-1]+(a[i]-a[i-1])*(i-1));
	}
	for(long long i = 1;i <= n;i++){
		long long r = i,l = 1;
		long long mid;
		if(pre[i] <= m){
			ans = max(ans,i);
			continue;
		}
		while(l < r){
			mid = (r + l) / 2;
			if(pre[i] - pre[mid] - (mid-1) * (a[i] - a[mid]) > m){
				l = mid+1;
			}
			else{
				r = mid;
			}
		}
		ans = max(ans,i - mid);
	}
	cout << ans;
	return 0;
} 
//Oct31==Dec25?
