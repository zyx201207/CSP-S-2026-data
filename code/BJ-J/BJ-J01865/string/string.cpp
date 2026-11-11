#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5+5;
int n;
ll a[N];
char c[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin>>n;
	ll L=0;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	ll ans=0;
	int l=1, r=n;
	while(l < r){
		if(a[l] < a[r]) {
			if(c[l] != c[r]) ans += a[l];
			a[r] -= a[l];
			a[l] = 0;
			l++;
		} else if(a[l] == a[r]){
			if(c[l] != c[r]) ans += a[l];
			a[l] = a[r] = 0;
			l++; r--;
		} else {
			if(c[l] != c[r]) ans += a[r];
			a[l] -= a[r];
			a[r] = 0;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
