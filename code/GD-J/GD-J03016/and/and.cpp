#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[1000005], maxe=-1e9, b[100005][8],q = 1, c = 0 ;
bool vis[10005][10005];
//void owo(ll a1, ll a2, ll an){
//	if (an == 0){     
//		return ;
//	}
//	vis[]
//	if (maxe and a1 > maxe) {
//		maxe = a1 and a2;
//		an--;
//	}
//	for (ll w = 0; w < n; w++){
//		owo (a1, a[w], );
//	}
//	
//}
int main(){
	cin >> n >> m;
	//二进制转换 
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		for (ll l = 1; l <= 8; l++ ) {
			b[i][l] = a[i] % 2 ; 
			a[i] /= 2;
		}
	}
//	owo
	for (ll  i = 1; i <= n; i++){
		for (ll  l = i + 1; l <= n; l++){
			for (ll  w = 1; w <= 8; w++){
				c += (b[i][w] and b[l][w]) * q;
				q*=2;
			}
			if (maxe < c) {
				maxe = c;
			}
			c = 0;
			q = 1;
		}
	}
	cout << maxe;
	return 0;
} 
