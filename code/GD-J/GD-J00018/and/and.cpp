#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		sort(a+1,a+n+1);
		cout << a[n];
		return 0;
	}
	if(n == m){
		for(int i = 1;i <= n;i++){
			ans = a[i] & ans;
		}
		cout << ans;
		return 0;
	 }
	if(m == 2){
	 	for(int i = 1;i <= n;i++){
	 		for(int j = 1;j < i;j++){
				ans = max(ans,a[i] & a[j]);
			}
	 	}
		cout << ans;
		return 0;
	}
	else{
		cout << 0;
	}
	
	return 0;
}
