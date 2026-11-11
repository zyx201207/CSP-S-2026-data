#include <bits/stdc++.h>
using namespace std;
long long cnt;
long long a[200005];
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m == 1){
		sort(a+1,a+n+1,greater<int>());
		cout << a[1];
		return 0;
	}
	if(m == n){
		long long ans = a[1];
		for(int i=2;i<=n;i++){
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if(m == 2){
		long long cnt = 0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt = max(cnt,(a[i]&a[j]));
			}
		}
		cout << cnt;
		return 0;
	}
	sort(a+1,a+n+1,greater<int>());
	cout << a[m];


	return 0;
}
