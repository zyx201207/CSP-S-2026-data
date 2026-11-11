#include <bits/stdc++.h>
using namespace std;
long long a[200002];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n,m;
	for(int i= 1; i<=n;i++){
		cin >> a[i];
	}
	int mx = 0;
	int l=1,r=m;
	int ans = a[1];
	for(;l<=n;l++){
		if(l <= r){
		for (int i = l+1; i <= r; i++){
			ans = ans & a[i];
		}
		}
		else{
			for (int i = l; ; i++){
				if(i==n+1) i = 1;
				ans = ans & a[i];
				if(i == r) break;
			}
		}
		mx = max(mx,ans);
		ans = a[l+1];
		if(r==n) r = 1;
		else r++;
	}
	cout << mx;
	return 0;
} 
