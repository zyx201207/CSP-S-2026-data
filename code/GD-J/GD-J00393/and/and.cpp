#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, m, number;
ll a[N];
ll mx = 0;
int ad(ll x,ll y){
	return (x & y);
}
int main(){
	freopen("ans.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%lld", &a[i]);
		if(a[i] > mx) mx = a[i]; 
	}
	if(m == 1){
		printf("%lld", mx);
	}else if(m == 2){
		mx = 0;
		for(int i = 1;i <= n;i++){
			int cnt = i + 1;
			while(cnt <= n){
				ll ans = ad(a[i], a[cnt]);
				if(ans > mx) mx = ans;
				cnt++;
			}
		}
		printf("%lld", mx);
	}else{
		mx = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				int cnt = j + 1;
				while(cnt <= n){
					ll ans = ad(ad(a[i], a[j]), a[cnt]);
					if(ans > mx) mx = ans;
					cnt++;
				}
			}
		}
		printf("%lld", mx);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
