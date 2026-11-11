#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m, a[512345];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	int d=a[2]-a[1];
	for(int i=1; i<=n; i++){
		if(m<d*(i-1)){
			printf("%d", i-1);
			return 0;
		}
		m-=d*(i-1);
	}
	printf("%d", n);
	return 0;
} 
