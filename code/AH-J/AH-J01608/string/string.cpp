#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int a[N];
char c[N];

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i] >> c[i];
	int l = 1, r = n;
	long long ans = 0;
	while(l < r){
		if(a[l] > a[r]){
			if(c[l] != c[r]) ans += a[r] * 1ll;
			a[l] -= a[r];
			r --;
		}
		else if(a[l] == a[r]){
			if(c[l] != c[r]) ans += a[l] * 1ll;
			l ++, r --;
		} 
		else{
			if(c[l] != c[r]) ans += a[l] * 1ll;
			a[r] -= a[l];
			l ++;
		}
	}
	cout << ans;
	return 0;
} 
