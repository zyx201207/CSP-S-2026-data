#include<bits/stdc++.h>
using namespace std;
int n,m,maxx;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 1){
		for(int i = 1;i <= n;i++){
			maxx = max(maxx,a[i]);
		}
		cout << maxx;
		return 0;
	}
	if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				maxx = max(maxx,a[i] & a[j]);
			}
		}
		return 0;
	}
	if(m == n){
		maxx = a[1];
		for(int i = 2;i <= n;i++){
			maxx &= a[i];
		}
		cout << maxx;
		return 0;
	}
	if(m == n - 1){
		int x[200010] = {};
		int y[200010] = {};
		int ans_qian = a[2];
		for(int i = 3;i <= n;i++){
			ans_qian &= a[i];
		}
		int ans_hou = a[n - 1];
		for(int i = n - 2;i >= 1;i--){
			ans_hou &= a[i];
		}
		maxx = max(maxx,max(ans_qian,ans_hou));
		for(int i = 1;i <= n - 2;i++){
			x[i] = x[i - 1] & a[i];
			y[n - i + 1] = y[n - i + 1 + 1] & a[n - i + 1];
		}
		for(int i = 2;i < n;i++){
			maxx = max(maxx,(x[i - 1] & y[i + 1]));
		}
		cout << maxx;
		return 0;
	}
	do{
		int ans = a[1];
		for(int i = 2;i <= m;i++){
			ans &= a[i];
		}
		maxx = max(maxx,ans);
	}while(next_permutation(a + 1,a + n + 1));
	cout << maxx;
	return 0;
}
