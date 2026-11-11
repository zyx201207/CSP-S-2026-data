#include<bits/stdc++.h> 
using namespace std;
const int N = 2e5 + 5;
int n,l,r,a[N];
long long ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i] >> c[i];
	}
	l = 1,r = n;
	while(l <= r){
		if(a[l] > a[r]){
			if(c[l] != c[r]) ans += a[r];
			a[l] -= a[r];
			a[r] = 0;
			r --;
		}
		else if(a[l] < a[r]){
			if(c[l] != c[r]) ans += a[l];
			a[r] -= a[l];
			a[l] = 0;
			l ++;
		}
		else{
			if(c[l] != c[r]) ans += a[l];
			a[l] = a[r] = 0;
			l ++;
			r --;
		}
	}
	cout << ans;
	return 0;
}
