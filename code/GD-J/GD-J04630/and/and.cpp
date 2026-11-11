#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans = 0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	ans = a[n-1];
	for(int i = n-1;i >= n-m;i--){
		ans &= a[i];
	}
	cout << ans;
	return 0;
} 
