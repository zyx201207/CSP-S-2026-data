#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
long long n,m,a[N],ans,l,r;
bool check(int p){
	if(p == 1){
		for(int i = 2;i <= n;i++){
			if(a[i] - a[i - 1] <= m) return 1;
		}
		return 0;
	}
	else{
		long long ans = 0;
		for(int i = 1;i < p;i++){
			ans += (a[p] - a[i]);
		}
		for(int i = p,j = 1;i <= n;i++,j++){
			if(ans <= m) return 1;
			else{
				if(i < n){
					ans -= (a[i] - a[j]);
					ans += (a[i + 1] - a[i]) * (p - 2);
					ans += (a[i + 1] - a[i]);
				}
			}
		}
		return 0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	l = 1,r = n;
	while(l <= r){
		long long mid = l + (r - l) / 2;
		if(check(mid)){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout << r;
	return 0;
}
