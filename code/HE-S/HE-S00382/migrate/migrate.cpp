#include <bits/stdc++.h>
using namespace std;
#define int long long
int C,t,n,D;
int a[2000005],to[2000005];
int d[5005][5005],c[5005][5005];
int read(){
	int res = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar(); 
	}
	while(c >= '0' && c <= '9'){
		res = (res<<3)+(res<<1)+c-'0';
		c = getchar();
	}
	return res*f;
}
int sol(int x){
	int l = x,r = n,mid,ans = 0;
	while(l <= r){
		mid = (l+r)/2;
		if(a[mid]-a[x] <= D) ans = mid,l = mid+1;
		else r = mid-1;
	}
	return ans;
}
void baoli(){
	for(int i = 1;i <= n;i++){
		to[i] = sol(i);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			c[i][j] = 0;
			d[i][j] = 2e18+1;
		}
	}
	for(int i = 1;i <= n;i++){
		d[i][i] = 0;
		c[i][i] = 1;
	}
	int ans = 0;
	for(int len = 2;len <= n;len++){
		for(int l = 1,r = len;r <= n;l++,r++){
			if(r <= to[l]) d[l][r] = c[l][r] = 1;
			else{
				if(d[to[l]][r] > 2e18){
					continue;
				}
				d[l][r] = d[l][to[l]]+d[to[l]][r];
				int res = 0;
				res += c[to[l]][r];
				if(to[l]-1 > l && d[l][to[l]-1]+d[to[l]-1][r] == d[l][r]) res += c[to[l]-1][r];
				if(to[l]-2 > l && d[l][to[l]-2]+d[to[l]-2][r] == d[l][r]) res += c[to[l]-2][r];
				c[l][r] = min(res,3ll);
				if(res == 2){
					//cout << l << " " << r << "\n";
					ans++;
					//cout << d[l][to[l]-1]+d[to[l]][r] << "! ";
				}
			}
		}
	}
	cout << ans << "\n";
}
void subA(){
	if(n == 1){
		cout << 0 << "\n";
		return; 
	}
	int d = a[2]-a[1];
	int cnt = D/d;
	if(cnt <= 1){
		cout << 0 << "\n";
		return;
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(i+2*cnt-1 <= n) ans++;
	}
	cout << ans << "\n";
}
void subB(){
	for(int i = 1;i <= n;i++){
		to[i] = sol(i);
	}
	int mid = 0;
	for(int i = 1;i <= n;i++){
		if(a[i]-a[1] <= D && a[n]-a[i] <= D){
			mid = i;
			break;
		} 
	}
	int ans = 0;
	for(int i = 1;i < mid;i++){
		if(to[i]-i <= 1) continue;
		ans += to[to[i]-1]-to[to[i]-2];
	}
	cout << ans << "\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C = read(),t = read();
	while(t--){
		n = read(),D = read();
		for(int i = 1;i <= n;i++){
			a[i] = read();
		}
		if(C <= 10){
			baoli();
			continue;
		}
		else if(C <= 12){
			subA();
			continue;
		}
		else{
			subB();
			continue;
		}
	}
	
	return 0;
}
/*
20 500
5 5
1 3 5 7 10
*/
