#include <bits/stdc++.h> 
#define ll long long
using namespace std;

inline ll read(){
	ll r=0, sgn=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') sgn=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		r=r*10+ch-'0';
		ch=getchar();
	}
	return r*sgn;
}

inline void voidread(){
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') ch=getchar();
}

const int N=2e6 + 6;
ll c, t, n, d, x[N], dist[N];

void solve_A(){
	n=read();
	d=read();
//	bool is_dc=(c==11 || c==12);
	bool is_dc=true; 
	
	x[1]=read(), x[2]=read();
	for(int i=3; i<=n; i++) voidread();
	
	if(n==1){
		cout << 0 << "\n";
		return;
	}
	

	
	if(n==2){
		if(d < x[2]-x[1]) cout << 0 << "\n";
		else cout << 1 << "\n";
	}
	ll dtx = x[2]-x[1]; // Delta x
	if(is_dc){
		ll ans = 0;
		ll step = d / dtx;
		if(step >= n || d <= dtx){
			cout << 0 << "\n";
		}else{
//			for(int u=1; u+2*step-1<=n; u++){
//				ans += step-1;
//			}
//			ans += (step-1)*(n-2*step+1);
//			for(int u=n-2*step+2; u+step+1<=n; u++){
//				ans += n-(u+step);
//			}
//			ans += (step-1)*(step-2) >> 1;
//			ans = (step-1)*(n-2*step+1)+((step-1)*(step-2)>>1);
			ans = n-2*step+1;
			cout << ans << "\n";
		}
	}else{
		cout << 0 << "\n";
	}
}

ll shortest_routes(int u, int v){
	dist[u] = 0;
	for(int i=u+1; i<=v-1; i++){
		ll mind = 0x3f3f3f3f;
		for(int j=i-1; j>=u && (x[i]-x[j]<=d); j--){
			mind = min(mind, dist[j]);
		}
		dist[i] = mind+1;
	}
	int rs=0; //i=v
	ll mind = 0x3f3f3f3f;
	for(int j=v-1; j>=u && (x[v]-x[j]<=d); j--){
		if(dist[j] < mind){
			mind = dist[j];
			rs = 1;
		}else if(dist[j] == mind){
			rs++;
		}
	}
	return rs;
}

void solve(){
	n=read();
	d=read();
	ll ans=0;
	for(int i=1; i<=n; i++) x[i]=read();
	if(n==1){
		cout << 0 << "\n";
		return;
	}
	for(int v=2; v<=n; v++){
		for(int u=1; u<=v; u++){
			if(shortest_routes(u,v)==2) ans++;
		}
	}
	cout << ans << "\n";
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c=read(), t=read();
	if(c==11 || c==12){
		while(t--) solve_A();
	}else{
		while(t--) solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
