#include<bits/stdc++.h>
using namespace std;

int n;
long long M, arr[500010];

bool check(int x){
	long long Min = 1e18, c = 0;
	for(int i=1; i<=n; i++){
		if(i >= x){
			if(i > x) c -= arr[i-1] - arr[i-x];
			c += (arr[i] - arr[i-1]) * (x - 1);
			Min = min(Min, c);
		}
		else{
			c += (arr[i] - arr[i-1]) * (i - 1);
		}
	}
	return Min <= M;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %lld", &n, &M);
	for(int i=1; i<=n; i++){
		scanf("%lld", &arr[i]);
	}
	sort(arr+1, arr+n+1);
	int l = 1, r = n;
	while(l < r){
		int m = (l + r + 1) / 2;
		if(check(m)) l = m;
		else r = m - 1;
	}
	printf("%d", l);
	return 0;
}
