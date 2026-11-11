#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, maxn=0;
	int a[200005];
	int dp[200005][200005];
	cin >> n  >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	} 
	if(n==1){
		cout << a[1];
		return 0;
	}
	if(m==1){
		sort(a+1, a+n+1);
		cout << a[n];
		return 0;
	}
	if(m==n){
		int k=a[1];
		for(int i=2; i<=n; i++){
			k &= a[i];
		}
		cout << k;
		return 0;
	}
	for(int i=1; i<n; i++){
		for(int j=i+1; j<=n; j++){
			if(a[i]&a[j]>=maxn) {
			maxn=a[i]&a[j];
			}
		}
	}
	cout << maxn;
	
	return 0;
} 
