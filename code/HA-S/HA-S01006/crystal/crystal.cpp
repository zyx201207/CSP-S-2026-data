#include<bits/stdc++.h>
#define N 500005
#define ll long long

using namespace std;
ll n, m, a[N], d[N], ans;

ll read(){
	ll w = 1, r = 0;
	char c = getchar();
	while(c < '0' || c > '9')w = (c == '-')?(-1):(w), c = getchar();
	while(c >= '0' && c <= '9')r = (r<<3)+(r<<1)+(c^48), c = getchar();
	return r*w;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read(), m = read();
	ll l = 1, now = 0;
	for(int i = 1; i <= n; i++)a[i] = read();
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; i++)d[i] = a[i+1] - a[i];
	for(int i = 1; i < n; i++){
		if(d[i]*(i-l+1) <= m-now){
			now += d[i]*(i-l+1);
		}else{
			while(d[i]*(i-l+1) > m-now){
				now -= a[i]-a[l];
				l++;
			}
			now += d[i]*(i-l+1); 
		}
		ans = max(ans, i-l+2);
	}
	cout << ans;
	return 0;
}
