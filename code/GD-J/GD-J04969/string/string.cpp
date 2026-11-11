#include <bits/stdc++.h>
using namespace std;
long long n,ans,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i] >> c[i];
	}
	int l = 0,r = n - 1;
	for(int i = 0;i < n;i++){
		if(a[l] > a[r]){
			if(c[l] != c[r]){
				ans += a[r];
			}
			a[l] -= a[r];
			a[r] = 0;
			r--;
		}
		else if(a[l] == a[r]){
			if(c[l] != c[r]){
				ans += a[l];
			}
			a[l] = 0;
			a[r] = 0;
			l++;
			r--;
		}
		else{
			if(c[l] != c[r]){
				ans += a[l];
			}
			a[r] -= a[l];
			a[l] = 0;
			l++;
		}
		if(r == l)break;
	}
	cout << ans;
	return 0;
}
