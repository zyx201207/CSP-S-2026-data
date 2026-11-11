#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;

int a[N];
char c[N];

signed main(){
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	
	int l = 1, r = n;
	int x = a[l], y = a[r];

	int ans = 0;

	while(l < r){
		if(c[l] == c[r]){
			int mn = min(x, y);
			
			x -= mn;
			y -= mn;
		}
		else{
			int mn = min(x, y);
			
			ans += mn;
			x -= mn;
			y -= mn;
		}
		
		if(!x){
			l++;
			x = a[l];
		}
		if(!y){
			r--;
			y = a[r];
		}
	}

	cout << ans;

	return 0;
}
/*

2 a
2 b
1 c



*/
