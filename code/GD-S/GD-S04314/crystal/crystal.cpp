#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],n,m;
bool check(int x,int y){
	int sum = 0;
	int k = a[y];
	for(int i = x;i < y;i++){
		sum += k-a[i];
		if(sum > m){
			return false;
		}
	}
	return true;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	if(n <= 5000){
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		sort(a+1,a+n+1);
		int ans = 1;
		for(int i = 1;i <= n;i++){
			int l = 1,r = i;
			while(l < r){
				int mid = (r-l)/2+l;
				if(check(mid,i)){
					r = mid;
				}else{
					l = mid+1;
				}
			}
			ans = max(ans,i-r+1);
		}
		cout << ans;
	}else{
		int d = 0;
		bool flag = true;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		sort(a+1,a+n+1);
		for(int i = 1;i <= n;i++){
			if(i == 1){
				continue;
			}
			else if(i == 2){
				d = a[i]-a[i-1];
			}else{
				if(d != a[i]-a[i-1]){
					flag = false;
				}
			}
		}
		if(flag){
			int i = 1,cnt = 1;
			while(m - i*d >= 0 && i < n){
				m -= i*d;
				i++;
				cnt++;
			}
			cout << min(cnt,n);
		}else{
			cout << 1;
		}
	}
	return 0;
}
