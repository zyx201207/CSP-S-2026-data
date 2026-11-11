#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ( (x)&-(x) )
const int N = 2e6+5;
int c , T , n ;
ll d , x[N];
int nxt[N] ;
ll dp[N];
ll sum(int x){
	ll res = 0;
	while( x ){
		res += dp[x];
		x -= lowbit(x);
	}
	return res;
}
void add(int x,ll y){
	while( x <= n ){
		dp[x] += y;
		x += lowbit(x); 
	}
}
bool checkA(){
	for(int i = 3;i <= n;i++) if( x[i]-x[i-1] != x[2]-x[1]) return false;
	return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	
	cin >> c >> T;
	while( T-- ){
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> x[i];
		for(int i = 1;i <= n;i++){
			nxt[i] = i;
			int l = i,r = n,mid;
			while( l <= r ){
				mid = l+r>>1;
				if( x[mid]-x[i] <= d ) {
					nxt[i] = mid;
					l = mid+1;
				}else r = mid-1;
			}
		}
		if( n <= 5000 ){
			ll ans = 0;
			for(int l = 1;l <= n;l++){
				for(int i = 1;i <= n;i++) dp[i] = 0;
				add(l,1) , add(nxt[l]+1,-1);
				for(int r = l,pp = nxt[l];r <= n;r++){
					if( r > pp ) pp = nxt[pp];
					ll p = sum(r);
					if( p == 2 ) ++ans;
					if( r == nxt[r] ) break;
					if( nxt[r] >= pp+1 )
						add( pp+1 , p ) , add( nxt[r]+1 , -p );
				}
			}
			cout << ans <<"\n";
		}else if( checkA() ){
			ll ans = 0;
			if( d <= x[2]-x[1] ) cout << "0\n";
			else {
				for(int i = 1;i <= n;i++)
					ans += nxt[ nxt[i] ] - nxt[i] - 1;
				cout << ans <<'\n';
			}
		}
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/ 
