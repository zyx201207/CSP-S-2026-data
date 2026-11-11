#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
int a[200010];
int ans = 0;

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	if(m == 1){
		cout << a[n];
		return 0;
	}
	if(m == 2){
		for(int i = 1;i <= n;i++)
			for(int j = i + 1;j <= n;j++){
				int x = a[i] & a[j];
				ans = max(ans,x);
			}
		cout << ans;
		return 0;		
	}
	if(m == n){
		ans = a[1];
		for(int i = 2;i <= n;i++)
			ans = ans & a[i];
		cout << ans;
		return 0;
	}
	if(m == n - 1){
		bool f = 0;
		int sum;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i != j&&f == 0){
					sum = a[j];
					f = 1;
					continue;
				}
				if(i != j){
					sum = sum & a[j];
				}
			}
			ans = max(ans,sum);
		}
		cout << ans;
		return 0;		
	}
	cout << a[n - m + 1];
	return 0;
}
