#include <bits/stdc++.h>
using namespace std;
int n, i;
long long m, arr[500003], cha[500003], cost[500003], mycheck=1LL;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %lld", &n, &m);
	for(i=1; i<=n; i++) scanf("%lld", &arr[i]);
	sort(&arr[1], &arr[n+1]);
	
	cha[1] = arr[2]-arr[1];
	int _min_ok = (cha[1]<=m)? 1:0;
	for(i=2; i<=n-1; i++){
		cha[i] = arr[i+1]-arr[i];
		if(cha[i]<0) cha[i] = 1e18+9;
		if(cha[i]!=cha[i-1]) mycheck = 0;
		if(_min_ok==0 && cha[i]<=m) _min_ok=1;
	}
	if(!_min_ok){
		printf("1");
		return 0;
	}
	if(mycheck){
		if(cha[1]==0){
			printf("%d", n);
			return 0;
		}
		for(int j=1;j<=n-1;j++){
			if((1LL*j*j+j)/2 > m/cha[1]){
				printf("%d", j);
				return 0;
			}
		}
	}
	
	for(i=2; i<=n-1; i++){
		mycheck = 0;
		for(int p=1;p<=n-i-1;p++){
			cost[p] = cost[p]+cha[p+i-1]*i;
			if(cost[p]<0) cost[p] = 1e18 +9;
			if(cost[p]<=m) mycheck = 1;
		}
		if(!mycheck){
			printf("%d", i);
			return 0;
		}
	}
	printf("%d", n);
	return 0;
}
