#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool f = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != i){
			f =0;
		}
	}
	if(f && m + 1 < n){
		cout << m + 1;
		return 0;
	}else if(f){
		cout << n;
		return 0;
	}
	f = 1;
	for(int i = 3; i <= n; i++){
		if(a[i - 1] - a[i] != a[i - 2] - a[i - 1]){
			f = 0;
		}
	}
	if(f && n > 3){
		int j = abs(a[1] - a[2]);
		while(m > 0){
			j += abs(a[1] - a[2]);
			ans++;
			m -= j;
		}
		cout << ans++;
		return 0;
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1; i <= n; i++){
		int k = m,xb = i - 1,dqs = a[xb];
		int cnt = 1;
		while(k--){
			if(xb < 1){
				break;
			}if(dqs == a[i]){
				xb--;
				dqs = a[xb];
				cnt++;
			}
			dqs++;
			
		}
		if(dqs == a[i]){
			cnt++;
		}
		ans = max(ans,cnt);
	}
	cout << ans;
	return 0;
} // 
