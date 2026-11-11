#include<bits/stdc++.h>
using namespace std;

int n ,m;

long long a[1000000];
long long b[1000000];
long long c[1000000];

int ans;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+1+n);
	for(int i = 2; i <= n; i++){
		b[i] = a[i] - a[i-1];
	}
	c[1] = c[0] = 0;
	for(int i = 1; i <= n; i++){
		c[i] = c[i-1] + a[i];
	}
	
	for(int i = 1; i <= n; i++){
		while(ans < i){
			ans++;
			if(ans == i && m < 1ll*ans*a[i] - c[i]){
				ans--;
				break;
			}else if(ans < i && m < 1ll*ans*a[i] - c[i] + c[i-ans-1]){
				ans--;
				break;
			}
		}
	}
	
	printf("%d", ans);
	return 0;
}
