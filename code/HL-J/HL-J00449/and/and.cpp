#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull; 
const int maxn = 2e5+5;
ull a[maxn];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	ull ans = 0,maxx = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if(i == 1){
			ans = a[i];
		}else{
			ans = ans&a[i];
		}
		maxx = max(maxx,a[i]);
	}
	if(m == n){
		cout << ans << endl;
		return 0;
	}
	if(m == 1){
		cout << maxx << endl;
		return 0;
	}
	if(m == 2){
		ans=0,maxx=0;
		for (int i = 1; i <= n; i++){
			for (int j = i+1;j<=n; j++){
				ans = a[i] & a[j];
				maxx = max(maxx,ans);
			}
		}
		cout << maxx << endl;
		return 0;
	}
	sort(a+1,a+n+1,greater<int>());
	ans=a[1];
	for (int i = 1; i <= m; i++){
		ans = ans & a[i];
	}
	cout << ans << endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
